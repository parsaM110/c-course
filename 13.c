#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>



int main(){

    int age;
     while(1){
        printf("Please enter your Age: ");
        if(scanf("%d", &age) == 1)
            break;
        else 
            //fseek(stdin, 0, SEEK_END);  
            //fflush(stdin)

            // 👆 these wont work because of issues with stdin
            while(getchar()!='\n');

           // scanf("%*[^\n]"); 

    }
    return 0;
}