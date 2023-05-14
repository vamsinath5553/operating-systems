#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a memory block
struct memory_block {
    int size;
    int allocated;
};

// Function to find the worst-fit memory block for a given size
int worst_fit(struct memory_block* blocks, int n, int size) {
    int index = -1;
    int max_size = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (!blocks[i].allocated && blocks[i].size >= size && blocks[i].size > max_size) {
            index = i;
            max_size = blocks[i].size;
        }
    }
    return index;
}

int main() {
    // Initialize memory blocks
    struct memory_block blocks[] = {
        {300, 0},
        {600, 0},
        {350, 0},
        {200, 0},
        {750, 0},
        {125, 0}
    };
    int n = sizeof(blocks) / sizeof(blocks[0]);

    // Process sizes to allocate
    int processes[] = {115, 500, 358, 200, 375};
    int m = sizeof(processes) / sizeof(processes[0]);

    // Allocate memory for each process using worst-fit algorithm
    for (int i = 0; i < m; i++) {
        int index = worst_fit(blocks, n, processes[i]);
        if (index != -1) {
            blocks[index].allocated = 1;
            printf("Process %d allocated to block %d of size %d KB.\n", i+1, index+1, blocks[index].size);
        }
        else {
            printf("Process %d cannot be allocated.\n", i+1);
        }
    }

    return 0;
}
