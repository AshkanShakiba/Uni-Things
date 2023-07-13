#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define READERS 5
#define COUNT_MAX 5

typedef struct {
    int count, read_count;
    pthread_mutex_t mutex;
    pthread_mutex_t rw_mutex;
} Shared;

int base_pid;
int shmid;

void writer();
void reader();

int main(int argc, char const *argv[])
{
    int pid;

    if ((shmid = shmget(IPC_PRIVATE, sizeof(Shared), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(-1);
    }

    Shared* sh_at;
    if ((sh_at = (Shared *)shmat(shmid, NULL, 0)) == (Shared *) -1) {
        perror("shmat");
        exit(1);
    }

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&(sh_at->mutex), &attr);
    pthread_mutex_init(&(sh_at->rw_mutex), &attr);

    if (shmdt(sh_at) == -1) {
        perror("shmdt");
        exit(1);
    }

    base_pid = getpid();

    pid = fork();
    if (pid == 0) { // child (writer) process
        writer();
        return 0;
    }

    for (int i = 0; i < READERS; i++)
    {
        if (getpid() == base_pid)
            pid = fork();
        else
            break;
    }
    if (pid == 0) { // child (reader) process
        reader();
        return 0;
    }


    if (getpid() == base_pid) // parent process
    {
        wait(NULL); // wait on writer
        for (int i = 0; i < READERS; i++) // wait on readers
        {
            wait(NULL);
        }
    }

    if(-1 == (shmctl(shmid, IPC_RMID, NULL)))
    {   
        perror("shmctl");
        exit(1);
    }   

    return 0;
}

void reader() {
    Shared* shared;
    if ((shared = (Shared *)shmat(shmid, NULL, 0)) == (Shared *) -1) {
        perror("shmat");
        exit(1);
    }
    int pid = getpid();

    bool done = 0;
    while (! done) {
        pthread_mutex_lock(&(shared->mutex));
        (shared->read_count)++;
        if (shared->read_count == 1) {
            pthread_mutex_lock(&(shared->rw_mutex));
        }
        pthread_mutex_unlock(&(shared->mutex));

        printf("Reader:\tPID: %d\tcount: %d\n", pid, shared->count);
        if (shared->count >= COUNT_MAX) {
            done = true;
        }

        pthread_mutex_lock(&(shared->mutex));
        (shared->read_count)--;
        if (shared->read_count == 0) {
            pthread_mutex_unlock(&(shared->rw_mutex));
        }
        pthread_mutex_unlock(&(shared->mutex));
        sleep(0.1);
    }

    if (shmdt(shared) == -1) {
        perror("shmdt");
        exit(1);
    }
}

void writer() {
    Shared* shared;
    if ((shared = (Shared *)shmat(shmid, NULL, 0)) == (Shared *) -1) {
        perror("shmat");
        exit(1);
    }
    int pid = getpid();

    bool done = 0;
    while (! done) {
        pthread_mutex_lock(&(shared->rw_mutex));

        shared->count++;
        printf("Writer:\tPID: %d\tcount: %d\n", pid, shared->count);
        if (shared->count >= COUNT_MAX) {
            done = true;
        }

        pthread_mutex_unlock(&(shared->rw_mutex));
        sleep(0.05);
    }

    if (shmdt(shared) == -1) {
        perror("shmdt");
        exit(1);
    }
}