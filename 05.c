#include <stdio.h>


int main(){

    int **A; // pointer -> pointer -> integer (or array of integer) but mostly they mean array

    int *ptr = &x;

    A = &ptr;

    // dereference: *(*A)

    // pthread_join is ** function
    // we used if we want to pass pointer to address to a function
    
    int A[2][3]; // i still int* and not int **

    int **B; // this is you have a array of pointers like:
    int *C[10]; // int **
    // so you can select different part of RAM
    // heap is always slower than stack

    char **C; // is mostly used for array of strings and also now you can put null for end of it

    // if we want to allocate to heap (we know stack | we define variable and put the address to pointer)

    int *data = NULL;

    // malloc give you heap memory
    //data = malloc(20);
    data = malloc(sizeof(int) * 5);


    

     // if not freed -> it would be memory leak

    *(data+0) = 100;
    *(data+1) = 200;
    *(data+2) = 300;

    free(data); // free the memory

    return 0;

}

