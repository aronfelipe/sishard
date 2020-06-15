#include <stdio.h>
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <stdlib.h>

typedef struct {
    int id;
} thread_barrier_args;

sem_t semaphore;
pthread_mutex_t m;
int counter = 0;

void *thread_n(void *v) {

    printf("\nEntered..\n"); 

    // critical section 
    // lock
    pthread_mutex_lock(&m);

    counter++;

    printf("%d", counter);
    
    if (counter == 10) {
        for (int i = 0; i < 10; i++) {
            sem_post(&semaphore); 
        }
    }

    // unlock
    pthread_mutex_unlock(&m);

    //wait
    sem_wait(&semaphore);

    //signal 
    printf("\nJust Exiting...\n"); 

    return NULL;
}

int main() {
    int n = 10;
    pthread_t tids[10];

    sem_init(&semaphore, 0, 0);
    
    pthread_mutex_init(&m, NULL);

    for (int i = 0; i < n; i++) {
        pthread_create(&tids[i], NULL, thread_n, NULL);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL);
    }

    return 0;
}
