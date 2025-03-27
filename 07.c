#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(){


    FILE *f;

    if( (f = fopen("testfile1.txt","w")) == NULL){
        printf("Failed to open file\n");
        exit(1);
    }

    char * data = "Hello world";
    // I am making it dynamic, so will use strlen but 
    //it can give me segmentation fault if the string have no \0

    if(fwrite(data, sizeof(char), strlen(data), f) != 11){ //11 * 1 Byte
    
        printf("Error!\n");
        exit(1);

    }
    printf("File Written Successfully\n");
    fclose(f); //if you don't close 
    if(chmod("testfile1.txt", 0600) == -1){ // linux permissions are 8base numbers (Octals)
        printf("Failed to set file permissions\n");
        exit(1);
    }
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