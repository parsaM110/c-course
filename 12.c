#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    printf("Hello\n");
    fork();
    fork();
    printf("Bye (%d)\n", getpid());

    return 0;
} 