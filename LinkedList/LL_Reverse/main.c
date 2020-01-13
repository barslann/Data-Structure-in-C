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

// reverse elements not links.
void reverse(struct Node *p)
{
    int A[count(p)];
    p = first;
    int i=0;
    while (p!=NULL) {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p=first; // bring p to the first again
    i--; // i points to last element now.
    
    while (p) {
        p->data = A[i--];
        p= p->next;
    }
}
// reverse links using 3 pointers
void reverse_links(struct Node *p)
{
    p=first;
    struct Node *q = NULL, *r=NULL;

    while (p!=NULL) {
        r=q;
        q=p;
        p = p->next;
        q->next =r;
    }
    first = q;
}

// recursion
void reverse_recursion(struct Node *p, struct Node *q)
{
    p=first;
    q = NULL;

    if (p!=NULL) {
        reverse_recursion(p, p->next);
        p->next =q;
    }
    else
    {
        first= q;
    }
    first = q;
}


int main() {
    int A[] = {10,20,20,20,30,40,80};
    createList(A,7);
    reverse(first);
    displayList(first);
    return 0;
}

