#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("ERROR\n");
        exit(-1);
    }
    double sum = 0;
    for (int i = 1; i < argc; i++) {
        printf("arg: %s\n", argv[i]);
        sum = sum + atof(argv[i]);
    }
    printf("Sum : %f \n", sum);
    return 0;
}