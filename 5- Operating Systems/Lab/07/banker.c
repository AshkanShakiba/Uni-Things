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
#include <semaphore.h>

#define NUMBER_OF_RESOURCES 6
#define NUMBER_OF_CUSTOMERS 4
#define MAX_CUSTOMER_ITERATION 10
#define MAX_FILE_NAME "maximum.txt"

sem_t mutex;

int available[NUMBER_OF_RESOURCES];
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES] = {0};
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

bool need_lt_work(int need_i[], int work[]);
bool is_safe_state();
int request_resources(int customer_num, int request[]);
int release_resources(int customer_num, int request[]);
void *customer_thread(int n);
void print_state();
char *req_to_str(int req[]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    if (argc < NUMBER_OF_RESOURCES + 1) {
        printf("Not enough arguments\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        available[i] = atoi(argv[i + 1]);
    }
    FILE *f_ptr = fopen(MAX_FILE_NAME,"r"); 
    if (f_ptr == NULL) 
    { 
        printf("%s not found.\n", MAX_FILE_NAME); 
        return 0; 
    }
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            fscanf(f_ptr, "%d", &maximum[i][j]);
            need[i][j] = maximum[i][j];
        }
    }
    print_state();

    sem_init(&mutex, 0, 1);

    pthread_t customer_threads[NUMBER_OF_CUSTOMERS];
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        pthread_create(&customer_threads[i], NULL, (void *) customer_thread, (void *)(intptr_t) i);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(customer_threads[i], NULL);
    }

    return 0;
}

bool need_lt_work(int need_i[], int work[]) {
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        if (need_i[i] > work[i]) {
            return false;
        }
    }
    return true;
}

bool is_safe_state() {
    int work[NUMBER_OF_RESOURCES];
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        work[i] = available[i];
    }

    bool finish[NUMBER_OF_CUSTOMERS] = {0};
    int finish_count = 0;
    bool changed;
    while (finish_count != NUMBER_OF_CUSTOMERS) {
        changed = false;
        for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++)
        {
            if (!finish[i] && need_lt_work(need[i], work)) {
                for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
                {
                    work[j] += allocation[i][j];
                }
                
                finish[i] = true;
                finish_count++;
                changed = true;
            }
        }
        if (!changed) {
            return false;
        }
    }
    return true;
}

int request_resources(int customer_num, int request[]) {

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        if (request[i] > need[customer_num][i] || request[i] > available[i]) {
            return -1;
        }
    }

    sem_wait(&mutex);

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        available[i] -= request[i];
        allocation[customer_num][i] += request[i];
        need[customer_num][i] -= request[i];
    }

    if (is_safe_state()) {
        sem_post(&mutex);
        return 0;
    }

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        available[i] += request[i];
        allocation[customer_num][i] -= request[i];
        need[customer_num][i] += request[i];
    }
    sem_post(&mutex);
    return -1;
}

int release_resources(int customer_num, int request[]) {
    sem_wait(&mutex);

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        available[i] += request[i];
        allocation[customer_num][i] -= request[i];
        need[customer_num][i] += request[i];
    }

    sem_post(&mutex);
}

void *customer_thread(int n) {
    int req[NUMBER_OF_RESOURCES];
    bool req_rel;
    int done;
    for (int i = 0; i < MAX_CUSTOMER_ITERATION; i++)
    {
        req_rel = rand() % 2;
        if (req_rel == 1) { // request
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
            {
                req[j] = rand() % (need[n][j] + 1);
            }
            done = request_resources(n, req);
            printf("Customer %d Requests [%s\b] -----> %s\n", n + 1, req_to_str(req), done == 0 ? "granted" : "not granted");
            
        } else { // release
            for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
            {
                req[j] = rand() % (allocation[n][j] + 1);
            }
            done = release_resources(n, req);
            printf("Customer %d Releases [%s\b]\n", n + 1, req_to_str(req));
        }
    }
    
}

char *req_to_str(int req[]) {
    char *ret = malloc(100);
    char buf[5] = {0};
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        sprintf(buf, "%d", req[i]);
        strcat(ret, buf);
        strcat(ret, " ");
    }
    return ret;
}

void print_state() {
    printf("Available:\n");
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++)
    {
        printf("%d ", available[i]);
    }
    printf("\n");

    printf("Maximum:\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            printf("%d ", maximum[i][j]);
        }
        printf("\n");
    }
    printf("Allocation:\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("Need:\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("===================\n");
}