#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


size_t copy_and_filter(const void *data, size_t count, size_t size,
                        void *out,int (*f)(const void *)){

    int out_counter = 0;
    for(int i = 0; i < count ;i++){
         if(f(  (void *) ( (char *) data+i*size) )!= 0){  
            memcpy(out+(out_counter++)*size, data+i*size, size);
        }
    }
    return out_counter;
}

int is_even(const void *x){
    int v = *((int *)x);
    return v % 2 == 0;
}

int main(){
    int A[10] = {5,6,7,8,9,10,11,12,13,14};
    int B[10];

    size_t count = copy_and_filter((const void *)A, 10, sizeof(int), (void *)B, is_even);
    for(int i=0; i<count; i++){
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;

}
