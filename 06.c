#include <stdio.h>
#include <stdlib.h>

struct Node{
        int data;
        struct Node *next; 
    };


struct Node  *linklist_add(struct Node *H, int data){

    struct Node *tmp = malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;

    while (H && H->next)
    {
        H = H->next;
    }
    if(H) 
        H->next = tmp;
     return tmp;

}


int main(){

    struct Node *head=NULL, *tail=NULL, *cur=NULL;

    // if we define simple variable in stack it is going to be automatic 
    // *cur we are changing the it to different places
    // head but is going to go to heap
    // we want to pass this linked list to different functions like delete , ... 

    
    tail = linklist_add(head, 10);
    if(!head){
        head = tail;
    }


    return 0;

}

