#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
} Process;

void sortProcessesByArrival(Process p[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int findNextProcess(Process p[], int n, int currt) {
    int min_time = __INT_MAX__;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].at <= currt && p[i].rt > 0) {
            if (p[i].rt < min_time) {
                min_time = p[i].rt;
                index = i;
            }
        }
    }
    return index;
}

void calculateTimes(Process p[], int n) {
    int currt = 0;
    int completed_processes = 0;
    bool isProcessRunning = false;
    int pind = -1;

    while (completed_processes < n) {
        if (!isProcessRunning) {
            pind = findNextProcess(p, n, currt);
            if (pind != -1) {
                isProcessRunning = true;
            }
        }

        if (isProcessRunning) {
            p[pind].rt--;
            if (p[pind].rt == 0) {
                p[pind].ct = currt + 1;
                p[pind].tat = p[pind].ct - p[pind].at;
                p[pind].wt = p[pind].tat - p[pind].bt;
                completed_processes++;
                isProcessRunning = false;
            }
        }
        currt++;
    }
}

int main() {
    int num;
    printf("Enter the number of processes: ");
    scanf("%d", &num);
    Process processes[num];

    for (int i = 0; i < num; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt;
    }

    sortProcessesByArrival(processes, num);
    calculateTimes(processes, num);

    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].at,
               processes[i].bt,
               processes[i].ct,
               processes[i].tat,
               processes[i].wt);
    }
    return 0;
}
