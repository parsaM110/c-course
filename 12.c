#include <stdio.h>

// MACRO function
#define ARRAY_SIZE(A) (sizeof(A)/sizeof(A[0]))

// definitely put () around computational macro

#define ERROR(MSG) fprintf(stderr, "%s\n", MSG)

// for multi line macro
#define ERROR2(MSG) fprintf(stderr, "Error:\n"); \
                    fprintf(stderr, "%s\n", MSG)

// in multi line if you use it after if which don't use {} second statement will be out of if scope or

#define ERROR3(MSG) do {fprintf(stderr, "Error:\n"); \
                        fprintf(stderr, "%s\n", MSG); \
                        }while(0)   // don't use ; here because we used to use ; in our c code



int main(){

    int DATA[20];

    printf("Count: %ld\n", ARRAY_SIZE(DATA));
    // there is no function call now | and less stack usage and more speed

    if(ARRAY_SIZE(DATA)^12){
        // if dont put () around your macro it becomes
        // this becomes  if(sizeof(DATA)/sizeof(DATA[0])^12){
        // which now ^ have more pritotry 

        ERROR("This is too big"); //put ;
    }

    return 0;

} 