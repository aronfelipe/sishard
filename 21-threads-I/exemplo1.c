
#include <pthread.h>
#include <stdio.h>

void *first(void *arg) {
    printf("Hello thread - First!\n");
    return NULL;
}

void *second(void *arg) {
    printf("Hello thread - Second!\n");
    return NULL;
}

void *third(void *arg) {
    printf("Hello thread - Third!\n");
    return NULL;
}

void *fourth(void *arg) {
    printf("Hello thread - Fourth!\n");
    return NULL;
}

int main() {
    pthread_t tid_first, tid_second, tid_third, tid_fourth;
    
    int first_ = pthread_create(&tid_first, NULL, first, NULL);
    int second_ = pthread_create(&tid_second, NULL, second, NULL);
    int third_ = pthread_create(&tid_third, NULL, third, NULL);
    int fourth_ = pthread_create(&tid_fourth, NULL, fourth, NULL);

    printf("Hello main\n");
    
    // pthread_join(tid_first, NULL);
    // pthread_join(tid_second, NULL);
    // pthread_join(tid_third, NULL);
    // pthread_join(tid_fourth, NULL);

    return 0;
}
