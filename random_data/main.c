#include "helper.h"
#include <stdio.h> // sizeof is from stdio

# define SIZE(A) sizeof(A)/ sizeof(A[0])

int main(){

    int buf[20];

    generate_random_numbers(buf, SIZE(buf), 10, 50);
    print_array(buf, SIZE(buf));

    return 0;


}

