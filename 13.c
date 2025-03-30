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
    signal(SIGINT, handler);


     while(1){
        printf("Please enter your Age: ");
        if(scanf("%d", &age) == 1)
            break;
        else 
            scanf("%*[^\n]"); 

    }
    return 0;
}