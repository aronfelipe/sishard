  
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct size_vector_sum {
    int size;
    double vector[50];
    double sum;
};

void *thread(void *_arg) {
    struct size_vector_sum *svs = (struct size_vector_sum*) _arg;
    svs->sum = 0.0;
    for (int i = 0; i < svs->size; i++) {
        svs->sum += svs->vector[i];
    }
}


int main() {
    pthread_t *tids = malloc(2 * sizeof(pthread_t));
    struct size_vector_sum *svs = malloc(2 * sizeof(struct size_vector_sum));
    
    printf("Type the length: ");

    int length;
    double number;
    
	scanf("%d", &length);
    svs[0].size = length/2;
    svs[1].size = length/2+(length%2);

    for (int i = 0; i < length/2; i++) {
        printf("Type the number: ");
        scanf("%lf", &number);
        svs[0].vector[i] = number;
    }

    for (int i = 0; i < length/2+(length%2); i++) {
        printf("Type the number: ");
        scanf("%lf", &number);
        svs[1].vector[i] = number;
    }
    
	
    for (int i = 0; i < 2; i++) {
        pthread_create(&tids[i], NULL, thread, &svs[i]);
    }
    
    
    for (int i = 0; i < 2; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("Final sum: ");
    printf("%f \n", svs[0].sum + svs[1].sum);
    
    return 0;
}