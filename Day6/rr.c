#include<stdio.h>

int main() {
    int count, n, t, r, flag=0, tq;
    int wt=0, tat=0, at[10], bt[10], rt[10], ct[10];
    printf("Enter Total Process:");
    scanf("%d",&n);
    r=n;
    for(count=0; count<n; count++) {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
    }
    printf("Enter Time Quantum:");
    scanf("%d",&tq);
    printf("\n\nProcess\t|Arrival Time|Burst Time|Completion Time|Turnaround Time|Waiting Time\n\n");
    for(t=0, count=0; r!=0;) {
        if(rt[count]<=tq && rt[count]>0) {
            t+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0) {
            rt[count]-=tq;
            t+=tq;
        }
        if(rt[count]==0 && flag==1) {
            r--;
            ct[count] = t;
            printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",count+1, at[count], bt[count], ct[count], ct[count]-at[count], ct[count]-at[count]-bt[count]);
            wt+=t-at[count]-bt[count];
            tat+=t-at[count];
            flag=0;
        }
        if(count==n-1)
            count=0;
        else if(at[count+1]<=t)
            count++;
        else
            count=0;
    }
    printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
    printf("Avg Turnaround Time = %f",tat*1.0/n);
    return 0;
}
