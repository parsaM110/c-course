#include <stdio.h>
#include <stdlib.h>

struct Node{
        int data;
        struct Node *next; // like calling function inside of it | you can do it 
    };


int main(){

    struct Node *head=NULL, *cur=NULL;

    cur = malloc(sizeof(struct Node));

    // (*cur).data = 100;
    // (*cur).next = NULL;

    // in c for dereference of structure to pointer you can use ->

    cur->data = 100;
    cur->next = NULL;

    return 0;

}

