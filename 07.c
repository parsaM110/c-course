#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(){


    FILE *f;
    char *name = "data.txt";
    struct stat fileinfo;

    if(stat(name, &fileinfo) == -1){
        fprintf(stderr, "Error geting file info\n");
        exit(1);
    }

    size_t file_size = fileinfo.st_size;
    char *file_content = malloc(file_size);

    if( (f = fopen(name,"r")) == NULL){
        printf(stderr, "Failed to open file\n");
        exit(1);
    }

    char buffer[4096]; //block size (hard use block not byte for measure)

    //how to prevent stack overflow ?
    // it is in stack if you read a lot in stack, this can happen
    // in heap also makes performance issues
    // so we also make a fixed size buffer 
    // and in some cases if you have additional 
    size_t size;
    size_t total=0;

    do{
        size = fread(buffer, sizeof(char), sizeof(buffer)/sizeof(char), f);
        memcpy(file_content+total, buffer, size);
        total += size;

    } while(size == 4096);


    printf("%ld bytes read from file\n", size);


    

    
    
    fclose(f); 
    free(file_content);

    return 0;
}

