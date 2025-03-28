#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void run_in_separated_process(){
    if(fork()!=0) return;

    // Do the process
    printf("Child is running .. (%d)\n", getpid());

    exit(0); // it goes and the parent code so exit to don't do it
}


int main(){
   
   printf("Started\n");

   run_in_separated_process();

   printf("Parent Done (%d)\n", getpid());

    return 0;
} 