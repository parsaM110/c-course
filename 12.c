#include <stdio.h>


#ifndef PI // if client has not given by client I give default value
#define PI 3.14
#endif





int main(){

    #include "12data.txt"
    // you can also do int Z[] = #include ... 
    // and there you just put {1,2,3,4} but you will get warnings
    // check the output by gcc -E ,,,

    double r;
    // Macros are not c statrements so no need to ; (just find and replace)

    #ifdef GREET 
    printf("Hello dear user \n");
    #endif


    printf("PLease enter circle radius: ");

    scanf("%lf", &r);

    double area = PI * r * r;

    printf("AREA: %.2f\n", area);

    return 0;

}