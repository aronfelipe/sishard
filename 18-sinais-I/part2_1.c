
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void main (int argc, char *argv[]) {
    pid_t child;
    int st;
    child = fork();
    if (child == 0){
        printf("%d\n", getpid());
        while(1) {

        }
    } else {
        wait(&st);

        if (WIFEXITED(st)) printf("Return: %d \n", WEXITSTATUS(st));
        if (WIFSIGNALED(st)) printf("Signal: %s \n", strsignal(WTERMSIG(st)));
        // printf(strsignal(WIFEXITED(st)));
        // printf("\n");
        // printf(strsignal(WIFSIGNALED(st)));
        // printf("\n");
        // printf(strsignal(WTERMSIG(st)));
        // printf("\n");
    }
}