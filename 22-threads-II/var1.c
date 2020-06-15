#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct soma_parcial_args {
    double *vetor;
    int start, end;

    pthread_mutex_t *m;
};

double sum = 0;
double variance = 0;

void *computa_media_variancia(void *_arg) {
    struct soma_parcial_args *spa = _arg;

    for (int i = spa->start; i < spa->end; i++) {
        if (spa->m != NULL) pthread_mutex_lock(spa->m);
        sum += spa->vetor[i];
        if (spa->m != NULL) pthread_mutex_unlock(spa->m);
    }

    if (spa->m != NULL) pthread_mutex_lock(spa->m);
    variance = sum / (double)spa->end;
    if (spa->m != NULL) pthread_mutex_unlock(spa->m);

    return NULL;
}

int main(int argc, char *argv[]) {
    double *vetor = NULL;
    int n;
    scanf("%d", &n);

    vetor = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }

    pthread_t ids[4];
    struct soma_parcial_args args[4];
    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    for (int i = 0; i < 4; i++) {
        args[i].vetor = vetor;
        args[i].start = i * n / 4;
        args[i].end = (i + 1) * n / 4;
        args[i].m = &m;
        if (i == 3) args[i].end = n;

        pthread_create(&ids[i], NULL, computa_media_variancia, &args[i]);

    }

    for (int i = 0; i < 4; i++) {
        pthread_join(ids[i], NULL);
    }

    pthread_mutex_destroy(&m);


    printf("Paralela: %lf\n", sum);
    printf("Variância paralela: %lf\n", variance);

    sum = 0;
    struct soma_parcial_args aa;
    aa.vetor = vetor;
    aa.start = 0;
    aa.end = n;
    aa.m = NULL;
    computa_media_variancia(&aa);

    printf("Sequencial: %lf\n", sum);
    printf("Variância sequencial: %lf\n", variance);

    return 0;
}