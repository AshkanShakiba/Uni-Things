#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define EAT_TIMES 1

pthread_mutex_t chopstick[5];

void *philosopher(int n)
{
    for (int i = 0; i < EAT_TIMES; i++)
    {
        printf("Philosopher %d is thinking.\n", n + 1);

        pthread_mutex_lock(&chopstick[n]);
        pthread_mutex_lock(&chopstick[(n + 1) % 5]);

        printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d].\n", n + 1, n, (n + 1) % 5);
        sleep(1);

        pthread_mutex_unlock(&chopstick[n]);
        pthread_mutex_unlock(&chopstick[(n + 1) % 5]);

        printf("Philosopher %d finished eating.\n", n + 1);
    }
}

int main()
{
    pthread_t threads[5];

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, (void *) philosopher, (void *)(intptr_t) i);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}