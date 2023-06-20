#include <stdio.h>
#include <stdbool.h>

#define NUM_BLOCKS 16
#define MIN_FILE_SIZE 1
#define INODE_BLOCKS 8
#define DATA_BLOCKS 8

typedef struct {
    int startBlock;
    int size;
} File;

void initializeDisk(bool disk[]) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        disk[i] = false;
    }
}

int allocateFile(bool disk[], int fileSize) {
    int startBlock = -1;
    int contiguousBlocks = 0;

    for (int i = INODE_BLOCKS; i < NUM_BLOCKS; i++) {
        if (!disk[i]) {
            if (contiguousBlocks == 0) {
                startBlock = i;
            }

            contiguousBlocks++;

            if (contiguousBlocks == fileSize) {
                // Allocate the blocks to the file
                for (int j = startBlock; j < startBlock + fileSize; j++) {
                    disk[j] = true;
                }

                return startBlock;
            }
        } else {
            contiguousBlocks = 0;
        }
    }

    return -1; // No contiguous blocks available
}

void printDiskStatus(bool disk[]) {
    printf("Disk Status:\n");
    for (int i = 0; i < NUM_BLOCKS; i++) {
        printf("Block %d: %s\n", i, disk[i] ? "Allocated" : "Free");
    }
}

int main() {
    bool disk[NUM_BLOCKS];
    File files[DATA_BLOCKS];
    int numFiles = 0;

    initializeDisk(disk);

    printf("Sequential File Allocation\n");
    printf("Disk Size: %d blocks\n", NUM_BLOCKS);
    printf("Minimum File Size: %d KB\n", MIN_FILE_SIZE);
    printf("Available Blocks for Allocation: %d to %d\n", INODE_BLOCKS, NUM_BLOCKS - 1);

    int fileSize;
    while (true) {
        printf("\nEnter the file size (KB) (Enter 0 to exit): ");
        scanf("%d", &fileSize);

        if (fileSize == 0) {
            break;
        }

        if (fileSize < MIN_FILE_SIZE || fileSize > DATA_BLOCKS) {
            printf("Invalid file size!\n");
            continue;
        }

        int startBlock = allocateFile(disk, fileSize);

        if (startBlock == -1) {
            printf("Not enough contiguous blocks available for the file!\n");
            break;
        }

        File newFile;
        newFile.startBlock = startBlock;
        newFile.size = fileSize;

        files[numFiles++] = newFile;

        printf("File allocated successfully!\n");
        printDiskStatus(disk);
    }

    printf("\nFiles Allocated:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("File %d: Start Block: %d, Size: %d KB\n", i + 1, files[i].startBlock, files[i].size);
    }

    return 0;
}

