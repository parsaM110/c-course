#include <stdio.h>
#include <stdlib.h>



int main(){

    // Variadic 
    //   %[fill][width|*][,][.perc]type
    // , (separate number by 3 digits)
    // perc is for precision 
    // fill empty by space or 0
    // * give with placeholder you should give 2 variadic for width



    // if use s in ptrinf for print string it should have /0 otherwise you get segmentation fault


    printf("Hello\t");
    printf("Result: %d \t %d \n",10 ,10); // get how many parameter it needs by seeing %
    
    printf("Result: %*d ###\n",5 ,10);
    printf("Result: %2d ###\n",1000);


    int age;
    printf("Age: ");
    scanf("%d", &age); //terminal either understand char or string (array of char)
    // so if you use c read, you have to use atoi for conversion to integer

    // if you enter 36 you get 2Byte data: [51][54] 

    //atoi is not secure though, use strtol (is called str2l)

    printf("Birth: %d\n", 2023-age);


    // why when we we enter   36test   invalid data it still works?

    // because it goes to place that cant be turn into number 

    //strtol gives you the address of end where it stopped conversion

    // for validating conversion subtract length of input to this address

    //scanf do all of these
    
    
    return 0;
}

