// Time Complexity : O(n)
// Space Complexity : O(n)  -- Because recursion uses stack. There will be n+1 actication record.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL; // first pointer declare and initialize as NULL

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

void displayListRecursive(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ",p->data);
        displayListRecursive(p->next);
    }
}

int main() {
    int A[] = {3,5,7,10,15};
    createList(A,5);
    displayListRecursive(first);
    return 0;
}

