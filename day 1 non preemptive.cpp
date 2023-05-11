#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_burst_time(struct Process processes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                swap(&processes[i], &processes[j]);
            }
        }
    }
}

void calculate_waiting_time(struct Process processes[], int n) {
    int i;
    processes[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void calculate_turnaround_time(struct Process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void calculate_average_times(struct Process processes[], int n, float *avg_waiting_time, float *avg_turnaround_time) {
    int i;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    *avg_waiting_time = total_waiting_time / n;
    *avg_turnaround_time = total_turnaround_time / n;
}

void print_table(struct Process processes[], int n) {
    int i;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct Process processes[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };
    int n = sizeof(processes) / sizeof(struct Process);
    float avg_waiting_time, avg_turnaround_time;

    sort_by_burst_time(processes, n);
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
    calculate_average_times(processes, n, &avg_waiting_time, &avg_turnaround_time);
    print_table(processes, n);

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
