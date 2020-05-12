#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/resource.h>

// Children with wait and nanosleep

int main() {
    pid_t pai, filho;
    struct timespec tim, tim2;
    tim.tv_nsec = 0;
    
    for (int i = 1; i <= 8; i++) {
        filho = fork();
        tim.tv_sec = i;

        if (filho == 0) {
            pai = getppid();
            waitpid(filho = getpid());

            nanosleep(&tim , &tim2);

            printf("Eu sou o processo filho %d, meu pai é %d\n", filho, pai);
            break;
        } else {
            wait(NULL); /* reaping parent */
        }
    }
    return 0;
}
