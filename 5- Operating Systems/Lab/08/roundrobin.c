#include<stdio.h>
#include "time.h"

struct process {
    int pid;
    int bt;
    int wt;
    int tt;
    int ar;
};
struct process p[100];
int l, r, TQ, n, cur;

int main() {

    int sum_wt = 0, sum_tt = 0;
    int burstTime_tmp[20];
    float average_wt, average_tt;
    clock_t startTime = clock();
    printf("\nNumber of Processes:\t");
    scanf("%d", &n);
    printf("\n Time Quantum= ");
    scanf("%d", &TQ);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Burst Time P[%d]= ", p[i].pid);
        scanf("%d", &p[i].bt);
        burstTime_tmp[r++] = i;
        p[i].wt = -p[i].bt;
    }

    for (; l < r; l++) {
        int i = burstTime_tmp[l];
        if (p[i].bt > TQ) {
            cur += TQ;
            p[i].bt -= TQ;
            burstTime_tmp[r++] = i;
        } else {
            cur += p[i].bt;
            p[i].tt = cur;
            p[i].wt += p[i].tt;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("P[%d] => waiting time %d.\n", p[i].pid, p[i].wt);
        printf("P[%d] => turn around time %d.\n", p[i].pid, p[i].tt);
        sum_tt += p[i].tt;
        sum_wt += p[i].wt;
    }


    average_wt = (float) sum_wt / n;
    average_tt = (float) sum_tt / n;
    printf("\n\nAverage Waiting Time:\t%0.2f", average_wt);
    printf("\nAvg Turnaround Time:\t%0.2f\n", average_tt);
    clock_t endTime = clock();
    printf("\n##Total time= %f\n", (double) (endTime - startTime) / CLOCKS_PER_SEC);
    return 0;
}