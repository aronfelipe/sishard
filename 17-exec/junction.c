#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t child;

    char prog = "./par";
    int ret_par, st, number;
    char *args[3];

    do {
        scanf("Digite o valor: ", &number);
        if(fork() == 0) {
            sprintf(args[1], "%d", number);
            args[0] = prog;
            args[2] = NULL;
            execvp(prog, args);
        } else {
            wait(&st);
            if (WIFEXITED(st)) {
                ret_par = (char) WEXITSTATUS(st);
                if (ret_par == 0) {
                    printf("É ímpar\n");
                } else if (ret_par == 1) {
                    printf("É par\n");
                }
            }
        }

    } while (ret_par != -1);
    // // long argument;

    // // a lista de argumentos sempre começa com o nome do
    // // programa e termina com NULL
    
    // // argument = atol(received);

    
    // child = fork();
    // if (child == 0) {

    //     execvp(prog, args);

    // } else {
    //     wait(NULL); /* reaping parent */

    //     int wt;
    //     wait(&wt);
    //     if (WIFEXITED(wt)) {
    //         printf("Filhou acabou: %d\n",(char) WEXITSTATUS(wt));
    //     }

    //     int return_par = atof((char) WEXITSTATUS(wt));

    //     if (return_par == -1) {
    //         exit(-1);
    //     } else {
    //         main(argc, argv);
    //     }
    // }

    // return 0;
}
