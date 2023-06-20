#include<stdio.h>

void priorityScheduling(int burst_time[], int priority[], int n) {
    int waiting_time[n], turnaround_time[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // Calculate waiting time for each process
    waiting_time[0] = 0; // The first process has a waiting time of 0
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    // Calculate average waiting time and average turnaround time
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print the results
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n = 3; // Number of processes
    int burst_time[] = {30, 5, 12}; // Burst times of processes
    int priority[] = {2, 1, 3}; // Priorities of processes

    // Compute average waiting time and average turnaround time
    priorityScheduling(burst_time, priority, n);

    return 0;
}
