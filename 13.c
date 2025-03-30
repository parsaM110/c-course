#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void worker(){
    if(fork()!=0) return;
    printf("OK I am done (Child process - %d)\n", getpid());

    // ...
    exit(0); // we don't want it back it what is was  
}
int main(){
    worker();
    printf("ok I am done (main process - %d)\n", getpid());
    return 0;
}