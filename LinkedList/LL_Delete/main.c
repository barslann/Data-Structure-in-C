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

int count(struct Node *p)
{
    // Time Complexity = O(n) and Space=O(1)
    int count=0;
    while(p != NULL) // while(p != 0) or while(!p)
    {
        count++;
        p=p->next;
    }
    return count;
}

int delete(struct Node *p, int index)
{
    struct Node *q=NULL ; // to create a new node
    int x=-1,i=0; // to use in for loop
    
    // First we need to     check if index is valid or not
    if(index < 1 || index > count(p) )
        return -1;

        // if it is first node.
    if(index == 1)
    {
        q=first;
        x= first->data;
        first = first->next;
        free(q); // deallocate the memory
    }
    else // if it is not the first element
    {
        for (i=1; i< index-1; ++i) { // condition is index-1 because to get to the index we need to go index-1 step. Like if we want to insert at index 4, p will need to move 3 step.
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        free(p);
       
    }
    return x;
}

void insert_last(struct Node *p, int x)
{
    struct Node *t=NULL ; // to create a new node
    
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(first == 0)
    {
        first=last=t;
    }
    else
    {
        last->next = t;
        last = last->next;
    }
        
}

int main() {
    int A[] = {10,20,30,40,50};
    createList(A,5);
    delete(first,1);
    displayList(first);
    return 0;
}

