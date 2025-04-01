#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void test(){
    printf("Hello world\n");
}

void test2(int a){
    printf("Hello world %d!\n",a);
}

size_t copy_and_filter(const int *data, size_t count, int *out){
    // if you malloc you can allocate with exact size
    // but you cant get data from stack and you should use heap
    // I will malloc my self and will return the memory address 
    // I will return count and for error handling cant be used because size_t is unisigend int

    int out_counter = 0;
    for(int i = 0;i<count;i++){
        if(data[i] % 2 == 0){
            out[out_counter++] = data[i];
        }
    }
    return out_counter;
}

int main(){
    int A[10] = {5,6,7,8,9,10,11,12,13,14};
    int B[10];

    size_t count = copy_and_filter(A, 10, B);
    for(int i=0; i<count; i++){
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;

}
