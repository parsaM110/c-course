#include <stdio.h>
#include <stdlib.h>

int main(){


    FILE *f;

    f = fopen("testfile1.txt","w");

    if(fwrite("Hello world",1 ,11, f) != 11){ //11 * 1 Byte
    
        printf("Error!\n");
        exit(1);

    }
    printf("File Written Successfully\n");
    fclose(f); //if you don't close 

    return 0;
}

// if you now run :
/**

ll testfile1.txt 
-rw-rw-r-- 1 ubuntu ubuntu 11 Mar 27 21:50 testfile1.txt 


hexdump -C testfile1.txt 
00000000  48 65 6c 6c 6f 20 77 6f  72 6c 64                 |Hello world|
0000000b

*/