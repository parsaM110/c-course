#include <stdio.h>

int main(){

    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n", A[5]);

    int *ptr; // the target is int

    //ptr = &A; // it cuases warning (array is a pointer)
    ptr = A;

    printf("%d\n", *(ptr+5)); // it goes 5*size_of_data_ype

    *ptr = 20; // Dereference and write to target
    printf("%d\n", A[0]);


    return 0;
}