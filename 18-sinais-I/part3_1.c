
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>

void main (int argc, char *argv[]) {
    pid_t father, child;

    struct timespec tim, tim2;
    tim.tv_nsec = 0;
    tim.tv_sec = 10;

    int st;
    child = fork();
    if (child == 0){
        father = getppid();
        kill(getpid(),SIGINT);

    } else {
        wait(&st);
        if (WIFEXITED(st)) printf("Return: %d \n", WEXITSTATUS(st));
        if (WIFSIGNALED(st)) printf("Signal: %s \n", strsignal(WTERMSIG(st)));
        
        nanosleep(&tim , &tim2);
        kill (father, SIGKILL);

    }
}