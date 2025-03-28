#include <stdio.h>

#define PI 3.14
#define GREET


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