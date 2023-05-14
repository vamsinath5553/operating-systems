#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME 50

struct file {
    char name[MAX_NAME];
};

struct directory {
    char name[MAX_NAME];
    struct file files[MAX_FILES];
    int num_files;
};

int main() {
    struct directory cse;
    strcpy(cse.name, "CSE");
    cse.num_files = 0;

    // Adding files to the directory
    strcpy(cse.files[0].name, "A");
    cse.num_files++;

    strcpy(cse.files[1].name, "B");
    cse.num_files++;

    strcpy(cse.files[2].name, "C");
    cse.num_files++;

    // Displaying the directory and its files
    printf("Directory: %s\n", cse.name);
    printf("Number of files: %d\n", cse.num_files);
    for (int i = 0; i < cse.num_files; i++) {
        printf("%s\n", cse.files[i].name);
    }

    return 0;
}
