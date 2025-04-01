#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void *my_thread(void *data){

    sleep(5);
    printf("Hello Thread\n");
    return NULL; //if you don't want to return anything return NULL
}


int main(){

    pthread_t t1;
    // threads get void* and return void*

    pthread_create(&t1,NULL, my_thread, NULL);

    sleep(3);
    printf("main finished\n");
    void *ret;
    pthread_join(t1, &ret);
    return 0;

}