
#include <signal.h>
#include <unistd.h>

int counter = 0;

void sig_handler(int sig) 
{ 
    printf("Caught signal %d\n", sig);
    counter +=1;
    if (counter == 3) {
        exit(-1);
    }
} 
  
int main() 
{ 
    printf("Meu pid: %d\n", getpid());
    signal(SIGINT, sig_handler); 
    while (1) {

    }; 
    return 0; 
} 