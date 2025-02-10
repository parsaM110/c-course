#include <stdio.h>

// variables are both declaration and definition

int test(int a, int b); //declaration(prototype) and not definition
// void test(int , int ); // this is valid but  name the vars. for doc.
// a and b are in the stack of test not main
// everything you see are in the stack of itself(input vars. ,return types)


int main(int argc, char* argv[], char **envp){ // -> also get something from environment
//int main(int argc, char* argv[]) //-> get something from command line 
//int main(){

    int x=2,y=4;
    int c = test(x,y);
    // by compilers we have function call which copy the end of function addr.
    // we can change the end addr. and put it somewhere we want -> code injection


    return 0;

}

// now definition is to implement real body of function test
// RETURNTYPE NAME(TYPE NAME, TYPE NAME, ...)
// C DOESN'T HAVE OPTIONAL VALUE like java, python, ..
// we don't have function overloading -> two function with same name and overloading different input 
// we don't have namespaces , put all function in a file and give a name and use it from there
// in cpp like std:: boost:: and can have same name, but here in c all function name should be damn unique 
// we also don't have templates in like in cpp
// overloading means for different signatures (?) we have different functions (one take one input , other takes two float inputs)
// in template everything is same just dataType change by compiler
// ASM doesn't have functions it just have call
// ASM uses jump (first put the addr. in cpu register or stack then jump to func. and then jump back to addr.)
// only void func can have no return
int test(int a, int b){
    return a + b;
}

