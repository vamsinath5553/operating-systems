#include<stdio.h>

int main()
{
    int n=4; // number of processes
    int pid[n],at[n],bt[n],rt[n],ct[n],wt[n],tat[n],t=0,done=0,min,next;
    float avg_wt=0,avg_tat=0;

    // Process and arrival time input
    for(int i=0;i<n;i++)
    {
        printf("Enter Process ID, Arrival time and Burst time of Process %d: ",i+1);
        scanf("%d%d%d",&pid[i],&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    // SRPT algorithm implementation
    while(done<n)
    {
        min=9999;
        for(int i=0;i<n;i++)
        {
            if(rt[i]>0 && at[i]<=t && rt[i]<min)
            {
                min=rt[i];
                next=i;
            }
        }
        rt[next]--;
        if(rt[next]==0)
        {
            done++;
            ct[next]=t+1;
            tat[next]=ct[next]-at[next];
            wt[next]=tat[next]-bt[next];
            avg_tat+=tat[next];
            avg_wt+=wt[next];
        }
        t++;
    }

    // Printing the output
    printf("\n\n Process   Arrival Time   Burst Time   Completion Time   Waiting Time   Turnaround Time\n");
    for(int i=0;i<n;i++)
    {
        printf("    P%d            %d              %d              %d                %d                %d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\n\nAverage Waiting Time: %.2f ms\n",avg_wt/n);
    printf("Average Turnaround Time: %.2f ms\n",avg_tat/n);

    return 0;
}
