#include <stdio.h>
#include <stdlib.h>

struct _Node; //declare (in older c you have to use it like this but in newer no need for declare)
typedef struct _Node Node; //aliasing

struct _Node{ // _Node means it is internal
        int data;
        Node *next;  
        // in newer gcc versions you can say only by typedef: 
        // Node *next;
    };



Node  *linklist_add(Node *H, int data){

    Node *tmp = malloc(sizeof(Node));
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

void linklist_move(Node *H, size_t n)
{
    Node *tmp, *cur=H;
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

    Node *head=NULL, *tail=NULL, *cur=NULL;

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

