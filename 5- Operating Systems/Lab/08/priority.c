#include<stdio.h>
#include "time.h"

struct process {
    int pid;
    int bt;
    int wt;
    int tt;
    int pr;
};

struct process p[20];


void main() {
    int temp, n, i;
    clock_t startTime = clock();
    float average_wt, average_tt;
    int sum_wt = 0, sum_tt = 0;
    printf("Number of process= ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
    }

    for (i = 0; i < n; i++) {
        printf("Burst Time P[%d]", p[i].pid);
        scanf("%d", &p[i].bt);
        printf("Priority P[%d]", p[i].pid);
        scanf("%d", &p[i].pr);
    }

    //sort based on the priority
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].pr < p[j].pr) {
                temp = p[i].pr;
                p[i].pr = p[j].pr;
                p[j].pr = temp;

                temp = p[i].bt;
                p[i].bt = p[j].bt;
                p[j].bt = temp;

                temp = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = temp;
            }
        }
    }

    p[0].wt = 0; //initialized into zero
    p[0].tt = p[0].bt;
    sum_tt = p[0].tt;

    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].tt;
        sum_wt = sum_wt+ p[i].wt;
        p[i].tt = p[i].wt + p[i].bt;
        sum_tt = sum_tt+ p[i].tt;
    }

    printf("\nProcess\t    |Burst Time     |Waiting Time\t|Turnaround Time\n");
    printf("_____________________________________________________________");

    for (i = 0; i < n; i++) {
        printf("\n#P[%d]\t\t|%d\t\t\t    |%d\t  \t\t|\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
    }
    average_wt = (float) sum_wt / n;
    average_tt = (float) sum_tt / n;
    printf("\n Average Wait Time : %0.2f \n", average_wt);
    printf("\n Average Turn Around Time : %0.2f \n", average_tt);
    clock_t endTime=clock();
    printf("\n##Total time= %f\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
}