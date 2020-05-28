
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void main (int argc, char *argv[]) {
    pid_t child;
    int st;
    child = fork();
    if (child == 0){
        kill(getpid(),SIGINT);
    } else {
        wait(&st);
        if (WIFEXITED(st)) printf("Return: %d \n", WEXITSTATUS(st));
        if (WIFSIGNALED(st)) printf("Signal: %s \n", strsignal(WTERMSIG(st)));
    }
}