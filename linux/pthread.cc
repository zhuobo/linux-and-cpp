// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.27
// Filename:        pthread.cc
// Descripton:       

#include <stdio.h>
#include <pthread.h>

int             shared = 0;
pthread_mutex_t mutex;

void* thread_func(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("thread %d and old value is %d\n", *((int*)arg), shared);
    ++shared;
    printf("thread %d and new value is %d\n", *((int*)arg), shared);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[10];
    int threads_id[10];
    pthread_mutex_init(&mutex, NULL);
    for ( int i = 0; i < 10; ++i  ) {
        threads_id[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void*)&threads_id[i]);
    }
    for ( int i = 0; i < 10; ++i ) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
