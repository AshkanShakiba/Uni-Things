#include<stdio.h>
#include "time.h"

struct process {
    int pid;
    int bt;
    int wt;
    int tt;
    int ar;
};

struct process p[20];

int main() {
    int tmp[20];
    int i;
    int cnt = 0;
    int n;
    float sum_wt = 0, sum_tt = 0;
    float average_wt, average_tt;
    clock_t startTime = clock();
    printf("Number of process= ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Arrival Time P[%d]= \t", i + 1);
        scanf("%d", &p[i].ar);
    }
    for (i = 0; i < n; i++) {
        printf("Process Burst Time P[%d]= \t", i + 1);
        scanf("%d", &p[i].bt);
        tmp[i] = p[i].bt;
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
    }

    int j;
    int index;
    p[19].bt = 10000000;
    int current_time = 0;

    while (cnt != n) {
        index = 20-1;
        for (i = 0; i < n; i++) {
            if (p[i].ar <= current_time && p[i].bt < p[index].bt) {
                if (p[i].bt > 0) {
                    index = i;
                }
            }
        }
        p[index].bt--;

        if (p[index].bt == 0) {
            cnt++;
            j = current_time + 1;
            sum_wt +=  j - p[index].ar - tmp[index];
            sum_tt +=  j - p[index].ar;
        }
        current_time++;
    }

    average_wt = (float) sum_wt / n;
    average_tt = (float) sum_tt / n;
    printf("\n\n#Average Waiting Time= %0.2f", average_wt);
    printf("\n#Average Turnaround Time= %0.2f", average_tt);
    clock_t endTime = clock();
    printf("\n##Total time= %f\n", (double) (endTime - startTime) / CLOCKS_PER_SEC);
    return 0;
}