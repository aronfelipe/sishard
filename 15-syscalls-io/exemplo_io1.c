/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

int main (int argc, char *argv[]) {
    char arq1[100]; // nomes do arquivo, recebido via scanf
    char buf[1]; // local usado para guardar os dados lidos de arq1
    char response[64]; // local usado para guardar os dados lidos de arq1

    scanf("%s", arq1);
    int fd1 = open(arq1, O_RDONLY);

    int bytes_read = read(fd1, buf, 1);
    // int i = 0;

    printf("Arquivo lido: ");

    while (bytes_read > 0) {
        printf("%c", buf[0]);
        // response[i] = buf[0];
        bytes_read = read(fd1, buf, 1);
        // i++;
    }

    printf("\n");

    // printf("Arquivo lido: ");

    // for (int j = 0; j < i; j++) {
    //     printf("%c", response[i]);
    // }

    // printf("\n");

    close(fd1);
    
    return 0;
}
