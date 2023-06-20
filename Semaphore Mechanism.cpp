#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* process(void* arg) {
    int processId = *(int*)arg;

    printf("Process P%d is waiting for the semaphore.\n", processId);
    sem_wait(&semaphore);
    printf("Process P%d has acquired the semaphore.\n", processId);

 

    sem_post(&semaphore);
    printf("Process P%d has released the semaphore.\n", processId);

    return NULL;
}

int main() {
    sem_init(&semaphore, 0, 4);  // Initializing semaphore with 4 instances

    pthread_t threads[5];
    int processIds[5] = {1, 2, 3, 4, 5};  // Process IDs

    // Creating threads for processes P1, P2, P3, P4, P5
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, process, &processIds[i]);
    }

    // Waiting for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}

