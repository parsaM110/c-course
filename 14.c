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
        buf[i] = random() % 90 + 10;
}

// bubble sort
void sort(int *buf, size_t count){
    for(int i=0; i<count; i++)
        for(int j=0; j<count-1; j++)
            if(buf[j] > buf[j+1]){
                //xor swap -> for integer
                buf[j] = buf[j] ^ buf[j+1];
                buf[j+1] = buf[j+1] ^ buf[j];
                buf[j] = buf[j] ^ buf[j+1];
            }
}

int main(){
    int n[10];
    generate_randoms(n, SIZE(n));
    PRINT_ARRAY(n, SIZE(n));
    sort(n, SIZE(n));
    PRINT_ARRAY(n, SIZE(n));

}
