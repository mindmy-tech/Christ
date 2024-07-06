#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 5

// Shared buffer
int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

// Mutex and condition variables
pthread_mutex_t mutex;
pthread_cond_t not_full, not_empty;

// Producer function
void *producer(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Wait if the buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        // Produce an item and add it to the buffer
        buffer[in] = i;
        printf("Produced item %d\n", i);
        in = (in + 1) % BUFFER_SIZE;
        count++;

        // Signal the consumer that the buffer is not empty
        pthread_cond_signal(&not_empty);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Consumer function
void *consumer(void *arg) {
    int i, item;
    for (i = 0; i < 10; i++) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Wait if the buffer is empty
        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        // Consume an item from the buffer
        item = buffer[out];
        printf("Consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;

        // Signal the producer that the buffer is not full
        pthread_cond_signal(&not_full);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize the mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    // Create the producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}