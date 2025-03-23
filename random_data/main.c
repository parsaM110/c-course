#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// it is hard to use this damn sizeof
# define SIZE(A) sizeof(A)/ sizeof(A[0])

void generate_random_numbers(int *buf, size_t count, int min, int max);
void print_array(const int *buf, size_t count);


int main(){

    int buf[20];
    // generate_random_numbers(buf, sizeof(buf)/sizeof(buf[0]), 10, 50);
    // print_array(buf, sizeof(buf)/sizeof(buf[0]));

    generate_random_numbers(buf, SIZE(buf), 10, 50);
    print_array(buf, SIZE(buf));

    //remember random number for each 1 second

    return 0;


}

void generate_random_numbers(int *buf, size_t count, int min, int max){
    
    srandom(time(NULL));
    for(int i=0; i < count; i++){
        *(buf+i) = min + random() % (max - min+1);
    }

}

void print_array(const int *buf, size_t count){

    for(int i=0; i < count; i++){
        printf("%d ", *(buf + i));
    }

    printf("\n");

}