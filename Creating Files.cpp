#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 10

int main() {
    char filename[50];
    char data[MAX_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Create a file using system call
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error creating the file");
        exit(1);
    }

    printf("Enter data to write into the file (max %d characters):\n", MAX_SIZE);
    scanf(" %[^\n]", data);

    // Write data into the file
    int bytes_written = write(fd, data, sizeof(data));
    if (bytes_written == -1) {
        perror("Error writing to the file");
        exit(1);
    }

    close(fd);

    printf("Data written to the file successfully.\n");

    // Read data from the file and print it in the console
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from the file");
        exit(1);
    }

    printf("\nData read from the file:\n");
    printf("%.*s\n", bytes_read, buffer);

    close(fd);

    return 0;
}

