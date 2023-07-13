#include<stdio.h>
#include "time.h"

struct process {
    int pid;
    int bt;
    int wt;
    int tt;
};

struct process p[20];

int main() {
    int n;
    int i, j;
    float average_wt, average_tt;
    int sum_wt = 0, sum_tt = 0;
    clock_t startTime = clock();
    printf("Number of process= ");
    scanf("%d", &n);

    printf("\nProcess Burst Time\n");

    for (i = 0; i < n; i++) {
        printf("*P[%d]:", i + 1);
        scanf("%d", &p[i].bt);
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
    }

    p[0].wt = 0; //initial to zero

    //calculate waiting time
    for (i = 1; i < n; i++) {
        p[i].wt = 0;
        for (j = 0; j < i; j++)
            p[i].wt = p[i].wt + p[j].bt;
    }

    printf("\nProcess\t    |Burst Time     |Waiting Time\t|Turnaround Time\n");
    printf("_____________________________________________________________");

    int count = 0;
    //calculate turnaround time
    for (i = 0; i < n; i++) {
        p[i].tt = p[i].bt + p[i].wt;
        sum_wt = sum_wt + p[i].wt;
        sum_tt = sum_tt + p[i].tt;
        printf("\n#P[%d]\t\t|%d\t\t\t    |%d\t  \t\t|\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
        count++;
    }

    average_wt = sum_wt / (float) count;
    average_tt = sum_tt / (float) count;
    printf("\n\n#Average Waiting Time= %0.2f", average_wt);
    printf("\n#Average Turnaround Time= %0.2f", average_tt);
    clock_t endTime = clock();
    printf("\n##Total time= %f\n", (double) (endTime - startTime) / CLOCKS_PER_SEC);
    return 0;
}