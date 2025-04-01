#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE(A) (sizeof(A)/sizeof(A[0]))
#define PRINT_ARRAY(A,C)  do{\
                            for(int i=0; i<C; i++)\
                                printf("%d ",A[i]);\
                            printf("\n");\
                        }while (0);
#define SWAP(A,B) do{A =A ^ B; B = B ^ A; A= A ^ B;}while(0);

static inline void generate_randoms(int *buf, size_t count){
        srandom(time(NULL));
    for(int i=0; i < 10; i++)
        buf[i] = random() % 90 + 10;
}

int is_greater(const void *p1, const void *p2){
    int a = *((int*) p1);
    int b = *((int *) p2);
    return a - b;  // you can do a > b also

}


// q sort
void sort(int *buf, size_t count){
    // for(int i=0; i<count; i++)
    //     for(int j=0; j<count-1; j++)
    //         if(buf[j] > buf[j+1]){
    //             SWAP(buf[j], buf[j+1]);
    //         }

    qsort(buf, count, sizeof(int), is_greater); 
}

int main(){
    int n[10];
    generate_randoms(n, SIZE(n));
    PRINT_ARRAY(n, SIZE(n));
    sort(n, SIZE(n));
    PRINT_ARRAY(n, SIZE(n));

}