#include <stdio.h>


#ifndef PI // if client has not given by client I give default value
#define PI 3.14
#endif





int main(){

    double r;

    #ifdef GREET 
    printf("Hello dear user \n");
    #endif


    printf("PLease enter circle radius: ");

    scanf("%lf", &r);

    if(r<=0){
        //fprintf(stderr, "Error in radius\n (01.c - 26)"); 
        // not good for big code
        fprintf(stderr, "Error in radius\n %s %d \n", __FILE__, __LINE__); 
        // these MACROs doesn't have # because users used them and become popular they add it

        // they mostly log in file, we here log in stdout
        fprintf(stderr, "Compiled at :\n %s %s \n", __DATE__, __TIME__); 
        // gives us compile time and date
        // good for -h switch

        fprintf(stderr, "Error in radius\n %s \n", __func__); 
        // macro  __PRETTY_FUNCTION__ is for cpp
    }

    double area = PI * r * r;

    printf("AREA: %.2f\n", area);

    return 0;

}