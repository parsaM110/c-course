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

void linklist_move(struct Node *H, size_t n)
{
    struct Node *tmp, *cur=H;
    int i =0;
    for(; i<n && cur && cur->next && cur->next->next; i++){
        cur = cur->next;
    }
    if((n-i) != -1){
            return ;
        }
    tmp = cur->next;
    cur->next = tmp->next;

    while(cur->next){
        cur = cur->next;
    }
    cur->next = tmp;
    tmp->next = NULL;
}


int main(){

    struct Node *head=NULL, *tail=NULL, *cur=NULL;

    // if we define simple variable in stack it is going to be automatic 
    // *cur we are changing the it to different places
    // head but is going to go to heap
    // we want to pass this linked list to different functions like delete , ... 

    for(int i=10; i<20; i++){
        int d;
        scanf("%d",&d);
        tail = linklist_add(head, d);
    }
    if(!head){
        head = tail;
    }


    return 0;

}

