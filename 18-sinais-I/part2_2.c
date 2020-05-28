#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char prog[] = "kill";
    // a lista de argumentos sempre começa com o nome do
    // programa e termina com NULL
    char *args[] = {"kill", "-s", "SIGKILL", argv[1], NULL}; 

    execvp(prog, args);
    printf("Fim do exec!\n");

    return 0;
}
