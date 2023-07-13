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
    int i, j;
    int n;
    int sum_wt = 0, sum_tt = 0;
    int temp;
    float average_wt, average_tt;
    clock_t startTime=clock();
    printf("Number of process= ");
    scanf("%d", &n);

    printf("\nProcess Burst Time:\n");

    for (i = 0; i < n; i++) {
        printf("*P[%d]:", i + 1);
        scanf("%d", &p[i].bt);
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i+1;
    }

    //sort cpu burst time in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].bt > p[j + 1].bt) {
                temp = p[j].bt;
                p[j].bt = p[j + 1].bt;
                p[j + 1].bt = temp;

                temp = p[j].pid;
                p[j].pid = p[j + 1].pid;
                p[j + 1].pid = temp;
            }
        }
    }

    p[0].wt = 0; //initial to zero

    //calculate waiting time
    for (i = 1; i < n; i++) {
        p[i].wt = 0;
        for (j = 0; j < i; j++) {
            p[i].wt = p[i].wt + p[j].bt;
        }
        sum_wt = sum_wt + p[i].wt;
    }


    printf("\nProcess\t    |Burst Time     |Waiting Time\t|Turnaround Time\n");
    printf("_____________________________________________________________");
    for (i = 0; i < n; i++) {
        p[i].tt = p[i].bt + p[i].wt;
        sum_tt = sum_tt + p[i].tt;
        printf("\n#P[%d]\t\t|%d\t\t\t    |%d\t  \t\t|\t%d", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
    }

    average_wt = (float) sum_wt / n;
    average_tt = (float) sum_tt / n;

    printf("\n\n#Average Waiting Time= %0.2f", average_wt);
    printf("\n#Average Turnaround Time= %0.2f\n", average_tt);
    clock_t endTime=clock();
    printf("\n##Total time= %f\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
}