#include <stdio.h>
#include <stdlib.h>


#define SIZE(A) (sizeof(A)/sizeof(A[0]))
#define PRINT_ARRAY(A,C)  do{\
                            for(int i=0; i<C; i++)\
                                printf("%d ",A[i]);\
                            printf("\n");\
                        }while (0);


static inline void generate_randoms(int *buf, size_t count){
        srandom(10);
    for(int i=0; i < 10; i++)
        buf[i] = random();
}

int main(){
    int n[10];
    generate_randoms(n, SIZE(n));
    PRINT_ARRAY(n, SIZE(n));

}

//problem with this code is in MACRO the method I use for print is for stack array
// for pointer arrays(allocated by malloc) it won't work (can't get the size because it is dynamic) -> segmentation fault
// it is better to get size manually and not documentation(no body read that)