#include <stdio.h>

void print_array(int[],size_t);
void print_array2(const int[],size_t);

int main(){

    int A[11] = {1,2,3,4,5,6,7,8,9,10,11};
    print_array2(A,3);
    // print_array(A,sizeof(A)/sizeof(A[0]));


    return 0;
}

void print_array(int ARR[], size_t nmemb){ 
    

    for(int i=0; i< nmemb; i++){ 
        printf("%d\n", ARR[i]); 

    }
}

void print_array2(const int *ptr, size_t nmemb){ 

    for(int i=0; i< nmemb; i++){ 
        // printf("%d\n", ptr[i]); // ptr[i] in c is like dereference and pointer arithmetic  == *(ptr+i)
        // printf("%d\n", *(ptr+i));
        printf("%d\n", *(ptr++));
    }
}