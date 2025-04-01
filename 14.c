#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE(A) (sizeof(A)/sizeof(A[0]))
#define PRINT_ARRAY(A,C)  do{\
                            for(int i=0; i<C; i++)\
                                printf("%d ",A[i]);\
                            printf("\n");\
                        }while (0);


static inline void generate_randoms(int *buf, size_t count){
        srandom(time(NULL));
    for(int i=0; i < 10; i++)
        //buf[i] = (int) (((double) random() / RAND_MAX)*90 + 10); // number between 10 - 100
    // RAND_MAX is 2^31 + 1 which you can compute but use macro instead
    // converting number and floating computation is bad and in some devices not supported
        buf[i] = random() % 90 + 10;
        //instead use %
}

int main(){
    int n[10];
    generate_randoms(n, SIZE(n));
    PRINT_ARRAY(n, SIZE(n));

}
