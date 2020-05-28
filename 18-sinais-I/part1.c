
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void main (int argc, char *argv[]) {
    int num, ret_eh_par, st;
    if (fork() == 0){
        int division = 100/0;
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