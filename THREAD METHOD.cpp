#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 2

int shared_data;
sem_t sem;

void* double_thread(void* arg) {
    int val;
    sem_wait(&sem);
    val = shared_data * 2;
    printf("Double Thread: %d\n", val);
    sem_post(&sem);
    return NULL;
}

void* five_thread(void* arg) {
    int val;
    sem_wait(&sem);
    val = shared_data * 5;
    printf("Five Thread: %d\n", val);
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    // Initialize semaphore
    sem_init(&sem, 0, 1);

    // Set initial shared data
    shared_data = 10;

    // Create threads
    pthread_create(&threads[0], NULL, double_thread, NULL);
    pthread_create(&threads[1], NULL, five_thread, NULL);

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&sem);

    return 0;
}
