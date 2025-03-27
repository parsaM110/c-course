#include <stdio.h>

// const double pi = 3.14; // goes to code segment (all const variables ) which is readonly and performant(advised in cpp)
# define PI 3.14 // in c it is better to use MACRO, I don't use memory here (always use Uppercase for Macro) and is like find and replace
// all messages
// buffer size
// magic numbers is better to use MACRO

int main(){

    double r;
    printf("PLease enter circle radius: ");

    //stdout is MACRO but is not Uppercase
    fprintf(stdout, "hello"); 
    
    scanf("%lf", &r);

    // double area = 3.14 * r * r; //magic number is ANTI pattern
    double area = PI * r * r;

    printf("AREA: %.2f\n", area);

    return 0;

}