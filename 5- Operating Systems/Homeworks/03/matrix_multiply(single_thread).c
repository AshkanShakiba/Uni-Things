#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define M 1000

int matrix1[M][M];
int matrix2[M][M];
int matrix3[M][M];

int main() {
    // initialize matrices
    for (int i = 0; i < M; i++) {ش
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
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // end time
    double elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
    printf("elapsed time: %f seconds\n", elapsed_time);

    return 0;
}
