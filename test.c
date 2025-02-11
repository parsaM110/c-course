#include <stdio.h>

void main(){
    int a = 5,i;

    i = ++a + ++a + a++;
    printf("🎇a is now %d\n", a);
    printf("i is now %d\n", i);
    i = a++ + ++a + ++a; // seems compiler makes a change in optimizing and this output 21 not 20
    printf("😀a  is now %d\n", a);
    printf("i is now %d\n", i);
    a = ++a + ++a + a++;
    printf("🤣a is now %d\n", a);
    printf("i is now %d\n", i);
}