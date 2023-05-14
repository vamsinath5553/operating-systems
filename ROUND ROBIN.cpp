#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct Process processes[] = {{1, 24, 0, 0, 0}, {2, 3, 0, 0, 0}, {3, 3, 0, 0, 0}};
    int n = sizeof(processes) / sizeof(struct Process);
    int quantum = 4;
    int current_time = 0;
    int completed_count = 0;
    
    while (completed_count < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].waiting_time = current_time - processes[i].burst_time;
                    processes[i].turnaround_time = current_time;
                    processes[i].remaining_time = 0;
                    completed_count++;
                }
            }
        }
    }
    
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    
    printf("Round Robin Scheduling with Quantum %dms\n", quantum);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2fms\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2fms\n", avg_turnaround_time);
    
    return 0;
}
