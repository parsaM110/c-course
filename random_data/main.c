#include <stdio.h> // sizeof is from stdio

# define SIZE(A) sizeof(A)/ sizeof(A[0])

void generate_random_numbers(int *buf, size_t count, int min, int max);
void print_array(const int *buf, size_t count);

// you can omit declaration but if the implementation is wrong gcc would not figure it out
// older gcc will throw error and not compile
// clang will throw error too

int main(){

    int buf[20];

    generate_random_numbers(buf, SIZE(buf), 10, 50);
    print_array(buf, SIZE(buf));

    return 0;


}

