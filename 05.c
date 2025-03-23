#include <stdio.h>

void print_array(int ARR[]){
    // size of array in ARR[10] is useless and not working
    //printf("%lu\n", sizeof(ARR)); // -> it is like pointer and cant print the size

    for(int i=0; i<10; i++){ // the 10 is static , well we can put it as param
        printf("%d\n", ARR[i]); // Magic Value -> 10 or use MACRO or constant (no hard code)

    }
}

int main(){

    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%lu\n", sizeof(A) / sizeof(int)); 
    printf("%lu\n", sizeof(A) / sizeof(A[0]));  // it have a bug when A[0] be empty but you never do it
    // sizeof is compile time instruction
    // dynamic memory like heap can't be used with sizeof like runtime
    // strlen is length of string
    // for dynamic you yourself has allocated it and have the size 


    int *ptr = A;
    printf("%lu\n", sizeof(ptr)); // in 64 bit system it is always 8 byte
    // do you now cant get the length of array by pointer
    printf("%lu\n", sizeof(*ptr));
    // it is not working no idea why

    print_array(A);
    return 0;
}