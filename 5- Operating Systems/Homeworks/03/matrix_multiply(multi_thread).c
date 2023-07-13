#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M 1000

int matrix1[M][M];
int matrix2[M][M];
int matrix3[M][M];

void *multiply(void *arg) {
    int i = *((int *) arg), j, k;
    for (j = 0; j < M; j++) {
        for (k = 0; k < M; k++) {
            matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
    pthread_exit(NULL);
}

int main() {
    // initialize matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    // start time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // calculate multiply of matrix
    pthread_t threads[M];
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < M; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i], NULL, multiply, arg);
    }
    for (int i = 0; i < M; i++) {
        pthread_join(threads[i], NULL);
    }

    // end time
    double elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
    printf("elapsed time: %f seconds\n", elapsed_time);

    return 0;
}
