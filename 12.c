#include <stdio.h>


#ifndef PI // if client has not given by client I give default value

// #error Your system is too old 

#warning Your system is old and application will run slowly

// #define PI 3.14
#endif





int main(){

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