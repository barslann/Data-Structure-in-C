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



void sorted_insert(struct Node *p, int x)
{
    struct Node *t,*q=NULL ; // q is tail pointer
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(first == 0)
    {
        first = t;
    }
    else
    {
        while(p && p->data < x){
            q= p;
            p=p->next;
        }
        
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else{
            t->next = p->next;
            q->next = t;
        }
        
    }
        
}


int main() {
    //int A[] = {10,20,30,40,50};
    //createList(A,5);
    
    sorted_insert(first, 35);
    displayList(first);
    return 0;
}

