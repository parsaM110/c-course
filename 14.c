#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void test(){
    printf("Hello world\n");
}

void test2(int a){
    printf("Hello world %d!\n",a);
}

size_t copy_and_filter(const int *data, size_t count, int *out, int (*f)(int)){

    int out_counter = 0;
    for(int i = 0;i<count;i++){
        if(f(data[i]) != 0){
            out[out_counter++] = data[i];
        }
    }
    return out_counter;
}

int is_even(int x){
    return x % 2 == 0;
}

int main(){
    int A[10] = {5,6,7,8,9,10,11,12,13,14};
    int B[10];

    size_t count = copy_and_filter(A, 10, B, is_even);
    for(int i=0; i<count; i++){
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;

}
