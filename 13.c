#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>



int main(){
    printf("Ok, going to background ...\n");

    sleep(5);

    // if(fork()!=0) exit(0); //parent is exited 
    if(fork()!=0) {
        sleep(10);
        exit(0);
    }



    sleep(60); // this is child
    return 0;
}