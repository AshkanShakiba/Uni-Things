#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>

#define SHM_KEY 102030
#define SHM_SIZE sizeof(int) * 25

sem_t mutex;

int create_segment()
{
    int shmid;
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, S_IRUSR | S_IWUSR)) == -1)
    {
        printf("error error error!");
        perror("shmget");
        exit(1);
    }
    return shmid;
}

int *attach_segment(int shmid)
{
    int *shm;
    if ((shm = shmat(shmid, NULL, 0)) == (int *)-1)
    {
        perror("Adding address space failed");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void detach_segment(int *shm)
{
    shmdt(shm);
}

void remove_segment(int shmid)
{
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("Removing failed");
        exit(EXIT_FAILURE);
    }
}

void print_histogram(int *hist, int number_of_samples)
{
    printf("Histogram for sample %d:\n", number_of_samples);
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < hist[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

double calculate(int number_of_samples)
{
    clock_t begin = clock();
    int shmid = create_segment();
    int *hist = attach_segment(shmid);
    srand(time(0));

    int rand_num, counter;
    if (fork() == 0)
    {
        for (int i = 0; i < number_of_samples / 2; i++)
        {
            counter = 0;
            for (int j = 0; j < 12; j++)
            {
                rand_num = rand() % 100;
                if (rand_num >= 49)
                    counter += 1;
                else
                    counter -= 1;
            }
            hist[counter + 12] += 1;
        }
        exit(0);
    }
    else
    {
        for (int i = 0; i < number_of_samples / 2; i++)
        {
            counter = 0;
            for (int j = 0; j < 12; j++)
            {
                rand_num = rand() % 100;
                if (rand_num >= 49)
                    counter += 1;
                else
                    counter -= 1;
            }
            hist[counter + 12] += 1;
        }
    }
	
    print_histogram(hist, number_of_samples);
    detach_segment(hist);
    remove_segment(shmid);
    clock_t end = clock();
    double time_spend = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;
    return time_spend;
}

int main(int argc, char *argv[])
{
    int number_of_samples = strtol(argv[1], NULL, 10);
    if (number_of_samples <= 0) return 0;
    
    double time_spend = calculate(number_of_samples);
    printf("Time= %f\n", time_spend);
    return 0;
}
