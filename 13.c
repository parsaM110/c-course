#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void handler(int sig){
    printf("\n\n\n SIGNAL %d HAPPEND\n", sig);
}

int main(){
    int age;
    if(signal(SIGINT, handler) == SIG_ERR)
        printf("Cannot handle signal SIGINT\n");
    if(signal(SIGKILL, handler) == SIG_ERR)
        printf("Cannot handle signal SIGKILL\n");


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