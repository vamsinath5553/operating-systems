#include <stdio.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

typedef struct {
    int size;
    int allocated;
} Partition;

typedef struct {
    int size;
    int partitionIndex;
} Process;

void worstFit(Partition partitions[], int numPartitions, Process processes[], int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        int maxBlockSize = -1;
        int maxBlockIndex = -1;

        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j].allocated == 0 && partitions[j].size >= processes[i].size) {
                if (partitions[j].size > maxBlockSize) {
                    maxBlockSize = partitions[j].size;
                    maxBlockIndex = j;
                }
            }
        }

        if (maxBlockIndex != -1) {
            partitions[maxBlockIndex].allocated = 1;
            processes[i].partitionIndex = maxBlockIndex;
        }
    }
}

int main() {
    Partition partitions[MAX_PARTITIONS] = {
        {40, 0},
        {10, 0},
        {30, 0},
        {60, 0}
    };

    Process processes[MAX_PROCESSES] = {
        {100, -1},
        {50, -1},
        {30, -1},
        {120, -1},
        {35, -1}
    };

    int numPartitions = 4;
    int numProcesses = 5;

    printf("Worst-Fit Memory Allocation Algorithm\n");
    printf("Memory Partitions:\n");
    for (int i = 0; i < numPartitions; i++) {
        printf("Partition %d: %d KB\n", i+1, partitions[i].size);
    }

    printf("\n");

    worstFit(partitions, numPartitions, processes, numProcesses);

    printf("Process Allocation:\n");
    for (int i = 0; i < numProcesses; i++) {
        if (processes[i].partitionIndex != -1) {
            printf("Process %d: %d KB - Allocated to Partition %d\n", i+1, processes[i].size, processes[i].partitionIndex+1);
        } else {
            printf("Process %d: %d KB - Not Allocated\n", i+1, processes[i].size);
        }
    }

    return 0;
}

