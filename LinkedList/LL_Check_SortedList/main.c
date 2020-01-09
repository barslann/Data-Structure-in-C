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

int isSorted(struct Node*p)
{
    int x = -65536 ;// min valu for 4 byte integer
    while (p != NULL) {
        if (p->data < x)
            return 0;
        else
        {
            x = p->data;
            p=p->next;
        }
    }
    return 1;
}


int main() {
    int A[] = {10,70,30,40,50};
    createList(A,5);
    if(isSorted(first))
        printf("It is sorted");
    else
        printf("It is NOT sorted");
        
    displayList(first);
    return 0;
}


