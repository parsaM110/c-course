#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>



int main(){
    // char buf[255];

    // while(1){
    //     printf("Please enter your name: ");
    //     // scanf("%s", buf);
    //     // scanf returns numbers of items it received 
    //     if(scanf("%s", buf) == 1)
    //         break;
    // }

    int age;
     while(1){
        printf("Please enter your Age: ");

        if(scanf("%d", &age) == 1)
            break;

        // if you give invalid number like test
        // it stays in scanf buffer
        // scanf doesn't consume it 
        // cause it always be fail
        // infinite printf loop
    }
    return 0;
}