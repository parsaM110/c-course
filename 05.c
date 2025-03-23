#include <stdio.h>

void print_array(int[],size_t);


int main(){

    int A[11] = {1,2,3,4,5,6,7,8,9,10,11};
    print_array(A,20000);
    // print_array(A,sizeof(A)/sizeof(A[0]));


    return 0;
}

void print_array(int ARR[], size_t nmemb){ 
    // nmemb : number of members (max: is pointer 64 byte)
    // but using long long unsigned int nmemb is only on my system
    // instead we use size_t
 

    for(int i=0; i< nmemb; i++){ // the 10 is static , well we can put it as param
        printf("%d\n", ARR[i]); // Magic Value -> 10 or use MACRO or constant (no hard code)

    }
}