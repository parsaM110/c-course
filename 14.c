#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void test(){
    printf("Hello world\n");
}

void test2(int a){
    printf("Hello world %d!\n",a);
}

int *copy_and_filter(const int *data, size_t count, int **out){
    // if you malloc you can allocate with exact size
    // but you cant get data from stack and you should use heap
    // I will malloc my self and will return the memory address 
    // I will return count and for error handling cant be used because size_t is unisigend int

    int out_counter =0;
    for(int i = 0;i<count;i++){
        if(data[i] % 2 == 0){
            out[out_counter++] = data[i];
        return out_counter;
        }
    }
}

int main(){
    //simple func 
    // test();


    // void() *
    void (*func)(int); //func is pointer function name

    func = test2;
    // or (both works)
    func = &test2;


    func(20); //is like test(20)
    return 0;

}
