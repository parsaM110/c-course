#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>



int main(){

    int age;
     while(1){
        printf("Please enter your Age: ");
        // there are lot of ways to empty buffer
        // you can put all buffers to garbage
        // this is one of the ways
        if(scanf("%d", &age) == 1)
            break;
        else    
            scanf("%*[^\n]"); 
        // read until new line 
        // if you were not successful empty the buffer
        // you can also use gets

        // you can use fflush
        // flush the buffer but for input stream it has not stable behaviour

    }
    return 0;
}