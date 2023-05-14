#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int buffer_index = 0;

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_not_full_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_not_empty_cond = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    for (int i = 1; i <= 4; i++) {
        pthread_mutex_lock(&buffer_mutex);
        while (buffer_index == BUFFER_SIZE) {
            printf("Buffer is full, producer is waiting...\n");
            pthread_cond_wait(&buffer_not_full_cond, &buffer_mutex);
        }
        buffer[buffer_index] = i;
        buffer_index++;
        printf("Producer produced %d\n", i);
        pthread_mutex_unlock(&buffer_mutex);
        pthread_cond_signal(&buffer_not_empty_cond);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&buffer_mutex);
        while (buffer_index == 0) {
            printf("Buffer is empty, consumer is waiting...\n");
            pthread_cond_wait(&buffer_not_empty_cond, &buffer_mutex);
        }
        int item = buffer[0];
        for (int i = 0; i < buffer_index - 1; i++) {
            buffer[i] = buffer[i+1];
        }
        buffer_index--;
        printf("Consumer consumed %d\n", item);
        pthread_mutex_unlock(&buffer_mutex);
        pthread_cond_signal(&buffer_not_full_cond);
    
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Consume an item in the beginning to show that the buffer is empty
    pthread_mutex_lock(&buffer_mutex);
    while (buffer_index == 0) {
        printf("Buffer is empty, waiting for producer to produce...\n");
        pthread_cond_wait(&buffer_not_empty_cond, &buffer_mutex);
    }
    int item = buffer[0];
    for (int i = 0; i < buffer_index - 1; i++) {
        buffer[i] = buffer[i+1];
    }
    buffer_index--;
    printf("Consumer consumed %d\n", item);
    pthread_mutex_unlock(&buffer_mutex);
    pthread_cond_signal(&buffer_not_full_cond);

    // Wait for the producer thread to finish producing
    pthread_join(producer_thread, NULL);

    return 0;
}
