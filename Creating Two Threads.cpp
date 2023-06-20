#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 20

void* printEvenNumbers(void* arg) {
    printf("Even Numbers: ");
    for (int i = 2; i <= MAX_NUMBER; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    pthread_exit(NULL);
}

void* printOddNumbers(void* arg) {
    printf("Odd Numbers: ");
    for (int i = 1; i <= MAX_NUMBER; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t evenThread, oddThread;

    // Create the even thread
    if (pthread_create(&evenThread, NULL, printEvenNumbers, NULL) != 0) {
        fprintf(stderr, "Error creating even thread\n");
        return 1;
    }

    // Create the odd thread
    if (pthread_create(&oddThread, NULL, printOddNumbers, NULL) != 0) {
        fprintf(stderr, "Error creating odd thread\n");
        return 1;
    }

    // Wait for the threads to finish
    if (pthread_join(evenThread, NULL) != 0) {
        fprintf(stderr, "Error joining even thread\n");
        return 1;
    }
    if (pthread_join(oddThread, NULL) != 0) {
        fprintf(stderr, "Error joining odd thread\n");
        return 1;
    }

    return 0;
}

