#include "libarea.h"
#include <stdio.h>


int main(){

    double r;

    printf("PLease enter circle radius: ");
    scanf("%lf", &r);

    double A = area(r);
    printf("AREA: %.6f\n", A);
    return 0;

}