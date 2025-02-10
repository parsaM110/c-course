#include <stdio.h>

// variables are both declaration and definition

void test(int a, int b); //declaration(prototype) and not definition


int main(){
    test(10,11);
    printf("hello");
    return 0;

}

// now definition is to implement real body of fucntion test
void test(int a, int b){
    printf("test")
}

