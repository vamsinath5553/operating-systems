#include <stdio.h>

#define MAX_PROCESS 3

typedef struct {
    int processId;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void sjf(Process processes[], int numProcesses) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    // Sort the processes based on burst time (shortest to longest)
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = 0; j < numProcesses - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap the processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    processes[0].waitingTime = 0;

    // Calculate waiting time and turnaround time
    for (int i = 1; i < numProcesses; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Calculate average waiting time and average turnaround time
    double averageWaitingTime = (double) totalWaitingTime / numProcesses;
    double averageTurnaroundTime = (double) totalTurnaroundTime / numProcesses;

    // Print the results
    printf("Shortest Job First Scheduling\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("Average Waiting Time: %.2lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", averageTurnaroundTime);
}

int main() {
    Process processes[MAX_PROCESS] = {
        {0, 2, 0, 0, 0},
        {1, 4, 0, 0, 0},
        {2, 8, 0, 0, 0}
    };
    int numProcesses = 3;

    sjf(processes, numProcesses);

    return 0;
}

