#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5 // Number of philosophers
#define LEFT (i+N-1) % N // Index of left neighbor
#define RIGHT (i+1) % N // Index of right neighbor
#define THINKING 0 // Philosopher is thinking
#define HUNGRY 1 // Philosopher is hungry
#define EATING 2 // Philosopher is eating

int state[N]; // Array to represent the state of each philosopher
pthread_mutex_t mutex; // Mutex to synchronize access to shared resources
pthread_cond_t cond[N]; // Condition variables to signal state changes

// Function to simulate philosopher thinking
void think(int i) {
    printf("Philosopher %d is thinking.\n", i);
    sleep(rand() % 3 + 1); // Sleep for 1-3 seconds
}

// Function to simulate philosopher eating
void eat(int i) {
    printf("Philosopher %d is eating.\n", i);
    sleep(rand() % 3 + 1); // Sleep for 1-3 seconds
}

// Function to check if philosopher can eat
void test(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&cond[i]);
    }
}

// Function for philosopher i to pick up forks
void pickup(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING)
        pthread_cond_wait(&cond[i], &mutex);
    pthread_mutex_unlock(&mutex);
}

// Function for philosopher i to put down forks
void putdown(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    pthread_mutex_unlock(&mutex);
}

// Function for philosopher i to run the simulation
void* philosopher(void* arg) {
    int i = (int)arg;
    while (1) {
        think(i);
        pickup(i);
        eat(i);
        putdown(i);
    }
}

int main() {
    // Initialize state array to THINKING
    for (int i = 0; i < N; i++)
        state[i] = THINKING;

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < N; i++)
        pthread_cond_init(&cond[i], NULL);

    // Create threads for each philosopher
    pthread_t tid[N];
    int args[N];
    for (int i = 0; i < N; i++) {
        args[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    // Clean up resources
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < N; i++)
        pthread_cond_destroy(&cond[i]);

    return 0;
}
