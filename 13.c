#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void handler(int sig){
    printf("\n\n\n SIGNAL %d HAPPEND\n", sig);
    // if you don't exit, it will continue its normal procedure
    goto(GETINPUT);
}

int main(){
    int age;
    signal(SIGINT, handler); //register


     while(1){
GETINPUT:
        printf("Please enter your Age: ");
        if(scanf("%d", &age) == 1)
            break;
        else 
            scanf("%*[^\n]"); 

    }
    return 0;
}