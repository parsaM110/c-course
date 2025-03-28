#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int test = 100;

    printf("Hello\n");
    //fork(); // copy-on-write
    pid_t res = fork();
    printf("Res: %d\n", res);
    test = 200; // lazy loading it have in linux
    // the memory doesn't copy itself completely 
    printf("Bye (%d): %d\n", getpid(), test);

    return 0;
} 