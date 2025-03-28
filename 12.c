#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int test = 100;

    printf("Hello\n");

    pid_t res = fork();
    if(res == 0){
        printf("I am child\n");
    }else{
        printf("I am parent\n");
    }

  
    printf("Bye (%d): %d\n", getpid(), test);

    return 0;
} 