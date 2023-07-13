#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int number_of_samples = strtol(argv[1], NULL, 10);
    if (number_of_samples <= 0) return 0;

    clock_t start = clock();
    int hist[25];
    for (int i = 0; i < 25; i++)
    {
        hist[i] = 0;
    }

    int counter = 0;
    srand(time(NULL));
    for (int i = 0; i < number_of_samples; i++)
    {
        counter = 0;
        for (int j = 0; j < 12; j++)
        {
            int random_number = rand() % 100;
            if (random_number >= 49)
            {
                counter++;
            }
            else
            {
                counter--;
            }
        }
        hist[counter + 12]++;
    }

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n", elapsed);
    for (int i = 0; i < 25; i++)
    {
        printf("%d ", hist[i]);
    }

    printf("\n");

    int i, j;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < hist[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
