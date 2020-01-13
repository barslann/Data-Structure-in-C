#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL; // first pointer declare and initialize as NULL

void createList(int A[],int n)
{
    // scan through the array and take one element at a time and create a linked list
    int i;
    struct Node *t,*last; // create temproray pointer node and last pointer
    first= (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last =first;
    
    for (i =1 ; i < n; ++i) {
        t= (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayList(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}


// The idea behind removing duplicates is that we have 2 pointers checkong current and next
void remove_duplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q!=NULL) {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }else
        {
            p->next = q->next;
            free(q);
            q= p->next;
        }
    }
}


int main() {
    int A[] = {10,20,20,20,30,40,50};
    createList(A,7);
    remove_duplicate(first);
    displayList(first);
    return 0;
}


