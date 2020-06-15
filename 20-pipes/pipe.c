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
void func1() {
    sleep(1);
    printf("print(\"Este e um comando python!\", 1, 2, 4//3, 4/3)\n");
}

void func2() {
    // complete aqui com exec
}


int main() {
    // crie o pipe e redireciona a saída do processo pai para
    // a entrada do filho ;)

    int buf = 0; // local usado para guardar os dados lidos de arq1
    int counter = 400;

    int fd[2];
    pipe(fd);
    fd[0]; //-> for using read end
    fd[1]; //-> for using write end

    pid_t f = fork();

    if (f == 0) {
        counter++;
        write(fd[1], &counter, 4);
        // func1();
    } else {
        read(fd[0], &buf, 4);
        printf("%d \n",  buf);
        // func2();
    }
}