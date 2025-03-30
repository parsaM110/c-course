#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void worker(){
    if(fork()!=0) return; // I want this only be for child and parent doesn't do this
    // if you uncomment this parent will see this too
    printf("OK I am done (Child process - %d)\n", getpid());

    // ...
    exit(0); // we want the code after worker() be specific for perent; 
    //if you comment it then child will do the code after worker() too
}
int main(){
    worker();
    printf("ok I am done (main process - %d)\n", getpid());
    return 0;
}