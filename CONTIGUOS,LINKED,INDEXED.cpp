#include <stdio.h>

#define BLOCK_SIZE 1
#define FILE_SIZE 100

int main() {
    int contiguousIO, linkedIO, indexedIO;

    // Contiguous allocation strategy
    contiguousIO = 1;  // Only one I/O operation to write the new block

    // Linked allocation strategy
    linkedIO = FILE_SIZE;  // Traverse the entire linked list to find the last block
    linkedIO += 1;  // One I/O operation to write the new block

    // Indexed allocation strategy
    indexedIO = 1;  // One I/O operation to write the new block
    indexedIO += 1;  // One I/O operation to write the new index block (assuming it's in memory)

    printf("Contiguous I/O operations: %d\n", contiguousIO);
    printf("Linked I/O operations: %d\n", linkedIO);
    printf("Indexed I/O operations: %d\n", indexedIO);

    return 0;
}
