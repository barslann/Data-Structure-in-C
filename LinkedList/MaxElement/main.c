#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

int max_element(struct Node *p)
{
    int max=INT_MIN; // which is -2147483648
    while(p) // while(p != 0) or while(p != NULL)
    {
        if(p->data > max)
            max= p->data;
        p=p->next;
    }
    return max;
}

int recursive_max_element(struct Node *p)
{
    int x=0;
    if(!p) // p == 0 or p==NULL
        return INT_MIN;
    else
    {
        x = recursive_max_element(p->next);
        if(x > p->data)
            return x;
        else
            return p->data;
        
        /*
         return x > p->data 
         */
    }
}

int main() {
    int A[] = {3,5,73,105,15};
    createList(A,5);
    //printf("%d ",recursive_count(first));
    printf("%d ",max_element(first));
    
    return 0;
}
