#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

void funcao_lenta() {
    for (int i = 0; i < 5; i++) {
        printf("Filho %d", i);
        sleep(2);
        printf(" -- Fim Filho %d\n", i);
    }
}

void funcao_lenta_pai() {
    for (int i = 0; i < 10; i++) {
        printf("Pai %d", i);
        sleep(1);
        printf(" -- Fim Pai %d\n", i);
    }
}

int main(int argc, char *argv[]) {
    /* TODO: preencher o main com os exercícios.
             as funções acima não devem ser modificadas */

    int temp = open(".temp", O_WRONLY | O_CREAT, 0700);

    pid_t filho = fork();

    if (filho == 0) {
        dup2(temp, 1);
        funcao_lenta();
    } else {
        funcao_lenta_pai();
        lseek(temp, 0, SEEK_SET);
        
    }

    return 0;
}
