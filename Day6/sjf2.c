#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int pid;
    int at;
    int bt;
    int rt;
    int st;
    int ct;
    int tat;
    int wt;
    int iscomp;
} Process;
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process proc[n];
    for(int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i);
        scanf("%d", &proc[i].at);
        printf("Enter burst time of process %d: ", i);
        scanf("%d", &proc[i].bt);
        proc[i].pid = i;
        proc[i].iscomp = 0;
        proc[i].rt = proc[i].bt;
        proc[i].st = -1;
    }
    int currt = 0;
    int comp = 0;
    while(comp != n) {
        int idx = -1;
        int min = 10000000;
        for(int i = 0; i < n; i++) {
            if(proc[i].at <= currt && proc[i].iscomp == 0) {
                if(proc[i].rt < min) {
                    min = proc[i].rt;
                    idx = i;
                }
                if(proc[i].rt == min) {
                    if(proc[i].at < proc[idx].at) {
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) {
            if(proc[idx].st == -1) {
                proc[idx].st = currt;
            }
            proc[idx].rt -= 1;
            currt++;
            if(proc[idx].rt == 0) {
                proc[idx].ct = currt;
                proc[idx].tat = proc[idx].ct - proc[idx].at;
                proc[idx].wt = proc[idx].tat - proc[idx].bt;
                proc[idx].iscomp = 1;
                comp++;
            }
        } else {
            currt++;
        }  
    }
    int tottat = 0;
    int totwt = 0;
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               proc[i].pid, proc[i].at, proc[i].bt,
               proc[i].ct, proc[i].tat, proc[i].wt);
        tottat += proc[i].tat;
        totwt += proc[i].wt;
    }

    printf("\nAverage Turnaround Time = %.2f\n", (float)tottat / n);
    printf("Average Waiting Time = %.2f\n", (float)totwt / n);
    return 0;
}
