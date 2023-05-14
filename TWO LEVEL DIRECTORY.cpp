#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 10

typedef struct {
    char name[20];
    int num_files;
    char files[MAX_FILES][20];
} User;

typedef struct {
    int num_users;
    User users[MAX_USERS];
} Directory;

int main() {
    Directory directory;
    directory.num_users = 0;
    int i, j, user_found, num_files;
    char user_name[20], file_name[20];

    // create user directories
    for (i = 1; i <= 3; i++) {
        sprintf(user_name, "user%d", i);
        directory.users[directory.num_users].num_files = 0;
        strcpy(directory.users[directory.num_users].name, user_name);
        directory.num_users++;
    }

    // create files for each user directory
    for (i = 0; i < directory.num_users; i++) {
        printf("Enter number of files for %s: ", directory.users[i].name);
        scanf("%d", &num_files);
        for (j = 0; j < num_files; j++) {
            printf("Enter name of file %d for %s: ", j+1, directory.users[i].name);
            scanf("%s", file_name);
            strcpy(directory.users[i].files[directory.users[i].num_files], file_name);
            directory.users[i].num_files++;
        }
    }

    // display directory contents
    for (i = 0; i < directory.num_users; i++) {
        printf("\n%s:\n", directory.users[i].name);
        for (j = 0; j < directory.users[i].num_files; j++) {
            printf("- %s\n", directory.users[i].files[j]);
        }
    }

    return 0;
}
