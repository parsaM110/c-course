#include <stdio.h>
#include <stdlib.h>


#define SIZE(A) (sizeof(A)/sizeof(A[0]))
#define PRINT_ARRAY(A)  do{\
                            for(int i=0; i<SIZE(A); i++)\
                                printf("%d ",A[i]);\
                            printf("\n");\
                        }while (0);

int main(){
    int n[10];

    srandom(10);
    for(int i=0; i < 10; i++)
        n[i] = random();

    
    PRINT_ARRAY(n);

}

//problem with this code is in MACRO the method I use for print is for stack array
// for pointer arrays(allocated by malloc) it won't work -> segmentation fault