#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(int *buffer, size_t count);
void print_array(const int *buf, size_t count);


int main(){

    int n;

    // for optical values we can use NULL for tloc in time
    // tloc is pointer because in past it used to be an array 
    // because there was no long type
    srandom(time(NULL));
    // n = (int)(((double) random() / RAND_MAX) * 100);
    // some system dont have float
    // n = random() % 101;

    // for 20 - 50 we can do 
    n = 20 + random () % 31;
    printf("%d\n", n);
    


}

void generate_random_numbers(int *buffer, size_t count){

    // srand : seed : and change the start point by time
    // urandom is by linux kernel and used by mouse and keyboard
    // in miliary or scientific usage they use physical random generator like radioactive or electronic devices
    // unsigned is dangerous (in signed if you overflow your will be negentlive but you cant figure it out in signed)

}

void print_array(const int *buf, size_t count){

}