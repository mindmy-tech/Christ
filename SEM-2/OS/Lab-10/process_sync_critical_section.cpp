#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define COUNT 1000000

int shared_variable = 0;
pthread_mutex_t mutex;

void* increment(void* arg) {
    for (int i = 0; i < COUNT; i++) {
        pthread_mutex_lock(&mutex);
        shared_variable++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed.\n");
        return 1;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment, NULL) != 0) {
            fprintf(stderr, "Thread creation failed.\n");
            return 1;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the final value of the shared variable
    printf("Final value of shared variable: %d\n", shared_variable);

    return 0;
}

