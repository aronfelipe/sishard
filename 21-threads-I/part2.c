
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *first(void *arg) {
    printf("Hello thread - First!\n");
    return NULL;
}

void *tarefa_print_i(void *arg) {
    int *i = (int *) arg;
    printf("%d\n ", *i);
    return NULL;
}

void *minha_thread(void *arg) {
    int *i = (int *) arg;
    printf("Hello thread! %d\n", *i);
}

void main () {

    // int *vi = malloc(4 * sizeof(int));
    pthread_t *tids = malloc(4 * sizeof(pthread_t));

    // for (int i = 0; i < 4; i++) {
    //     vi[i] = i;
    // }
    
    // for (int i = 0; i < 4; i++) {
    //     pthread_create(&tids[i], NULL, tarefa_print_i, &vi[i]);
    // }

    // for (int i = 0; i < 4; i++) {
    //     pthread_join(tids[i], NULL);
    // }

    for (int i = 0; i < 4; i++) {
        pthread_create(&tids[i], NULL, minha_thread, &i);
    }
}