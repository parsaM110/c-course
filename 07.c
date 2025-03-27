#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int get_file_info(const char *path, struct stat *info){

    struct stat info;
    if(stat(path, &info) == -1){
        // fprintf(stderr, "Error geting file info\n");
        // exit(1); //never use exit in function -> because if you are in middle of something it aborts
        // function should only except error
        // also it is better not to print in function
        return -1; 
    }

    return 0;

}

int read_file(const char *path, char *content, size_t blocksize){
    
    FILE *f;
    

    size_t file_size = fileinfo.st_size;

    char buffer[fileinfo.st_blksize];  // you could use statvfs too , it also applies to folders
    size_t size;
    size_t total=0;

     if( (f = fopen(name,"r")) == NULL){
        return -1;
        //fprintf(stderr, "Failed to open file\n");
        //exit(1);
    }

    do{
        size = fread(buffer, sizeof(char), sizeof(buffer)/sizeof(char), f);
        memcpy(content+total, buffer, size);
        total += size;

    } while(size == 4096);
      fclose(f); 
      return 0;

}

int main(){

    
    char *name = "data.txt";

    struct stat info;
    if(get_file_info(name, &info)){
        fprintf(stderr, "Error geting file info\n");
        exit(1);
    }

    char *file_content = malloc(info.st_size);
    if(read_file(name, file_content, info_st_blksize)){
        fprintf(stderr, "Failed to open file\n");
        exit(2);
    }

    free(file_content);
    // if you exit then this free won't work, now it is okay because by exit here we free memory

    return 0;
}

