#include <stdio.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};

void print_memory_status() {
    int i;
    printf("Memory Status: ");
    for (i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB\t", partitions[i]);
    }
    printf("\n");
}

void allocate_process(int process_size) {
    int i;
    for (i = 0; i < NUM_PARTITIONS; i++) {
        if (partitions[i] >= process_size) {
            printf("Allocated %d KB from partition %d.\n", process_size, i + 1);
            partitions[i] -= process_size;
            print_memory_status();
            return;
        }
    }
    printf("Unable to allocate %d KB to any partition.\n", process_size);
}

int main() {
    int i;
    printf("Initial ");
    print_memory_status();

    for (i = 0; i < NUM_PROCESSES; i++) {
        allocate_process(processes[i]);
    }

    return 0;
}
