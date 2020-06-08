
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *minha_thread(void *arg) {
    int *i = (int *) arg;
    printf("Hello thread! %d\n", *i);
}

void main () {

    pthread_t *tids = malloc(4 * sizeof(pthread_t));

    for (int i = 0; i < 4; i++) {
        int vector[2] = {i, i+1};
        pthread_create(&tids[i], NULL, minha_thread, &vector);
    }
}