#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(){


    FILE *f;

    if( (f = fopen("data.txt","r")) == NULL){
        printf("Failed to open file\n");
        exit(1);
    }

    char buffer[4096];
    int size;
    size = fread(buffer, sizeof(char), sizeof(buffer)/sizeof(char), f);
    // how to understand the file have ended when the buffer return something less than your buffer
    // if you again try to read it will block you
    // this is why you can use pipe
    printf("%d bytes read from file\n", size);

    // you can use stat.h to get the size in structure it provide
    // allocate regarding the size
    // but we dont do it usually

    // we dont have EOF or EOT 
    // in interactive protocols like telnet or ftp they use this
    // in http it is not http, the socket is closed after ending or the size is in header file

    
    
    fclose(f); 

    return 0;
}

