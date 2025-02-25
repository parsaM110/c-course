#include <stdio.h>

int TEST=0; 

int main(){

    int A[] = {1,2,3};
    printf("%d\n", A[2]);
    printf("%ld\n", A+2); //it is big so use %ld = stack address is bigger than global
    printf("%ld\n", &TEST);
    printf("%d\n", *(A+2));

    return 0;
}