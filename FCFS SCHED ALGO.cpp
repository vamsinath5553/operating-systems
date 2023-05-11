#include <stdio.h>

int main()
{
    int n = 3;
    int bt[] = {10, 15, 25};
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // calculate waiting time for each process
    wt[0] = 0; // first process has a waiting time of 0
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        total_wt += wt[i];
    }

    // calculate turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
    }

    // calculate average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
