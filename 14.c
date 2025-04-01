#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void test(){
    printf("Hello world\n");
}

void test2(int a){
    printf("Hello world %d!\n",a);
}

size_t copy_and_filter(const int *data, size_t count, size_t size,void *out,
                         int (*f)(const void *)){

    int out_counter = 0;
    for(int i = 0;i<count;i++){
        // if(f(data+i*size) != 0){    // void * -> no Pointer arithmetics
            // but in GCC void* + 1 works
         if(f(  (void *) ( (char *) data+i*size) )!= 0){  // this now is standard in C
         // casting to *char common is very popular for making it to pointer of bytes
         // and by this you can access to single bytes possible
            memcpy(out+out_counter*size, data+i*size, size);
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
