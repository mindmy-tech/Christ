#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int number = 0;

void *print_even(void *arg) {
    for (int i = 0; i < COUNT; i++) {
        pthread_mutex_lock(&mutex);
        while (number % 2 != 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", number++);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    for (int i = 0; i < COUNT; i++) {
        pthread_mutex_lock(&mutex);
        while (number % 2 == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", number++);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid_even, tid_odd;

    pthread_create(&tid_even, NULL, print_even, NULL);
    pthread_create(&tid_odd, NULL, print_odd, NULL);

    pthread_join(tid_even, NULL);
    pthread_join(tid_odd, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
