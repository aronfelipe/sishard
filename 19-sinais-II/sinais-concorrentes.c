#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int status = 0;

void operacao_lenta() {
    sleep(10);
}


void sigint_handler(int num) {
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);
    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num) {
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main() {
    /* TODO: registar SIGINT aqui. */
    struct sigaction s;
    s.sa_handler = sigint_handler; // aqui vai a função a ser executada
    sigemptyset(&s.sa_mask);

    sigaddset(&s.sa_mask, SIGTERM); // Bloqueia o SIGTERM quando SIGINT tiver sido acionado

    s.sa_flags = 0;
    sigaction(SIGINT, &s, NULL);

    /* TODO: registar SIGTERM aqui. */
    struct sigaction sigterm;
    sigterm.sa_handler = sigterm_handler; // aqui vai a função a ser executada
    sigemptyset(&sigterm.sa_mask);

    sigaddset(&sigterm.sa_mask, SIGINT); // Bloqueia o SIGINT quando SIGTERM tiver sido acionado

    sigterm.sa_flags = 0;
    sigaction(SIGTERM, &sigterm, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
