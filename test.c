#include <stdio.h>


void test1(int a,int b){
    int c = a + b;
    printf("%d/n", c);
}

void test2(){
    long long int a = 10;
    int b = 11;
    test1(a,b);
}


int main(){

    test2();
    return 0;
}
