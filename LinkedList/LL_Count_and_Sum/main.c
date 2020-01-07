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

int recursive_count(struct Node *p)
{
 // Time and Space Complexity is O(n)
    if(p == NULL)
        return 0;
    else
        return recursive_count(p->next) + 1;
        //return 1 + recursive_count(p->next); // same with the above
}

int recursive_count2(struct Node *p)
{
    int x = 0;
    if(p) // if p is not false or 0 or NULL
    {
        x = recursive_count2(p->next);
        return x + 1;
    }
    else
        return 0;
}

int sum(struct Node *p)
{
    // Time Complexity = O(n) and Space=O(1)
    int sum=0;
    while(p != NULL) // while(p != 0) or while(!p)
    {
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int recursive_sum(struct Node *p)
{
 // Time and Space Complexity is O(n)
    if(p == NULL)
        return 0;
    else
        return recursive_sum(p->next) + p->data;
        //return 1 + recursive_count(p->next); // same with the above
}

int recursive_sum2(struct Node *p)
{
    int x = 0;
    if(p) // if p is not false or 0 or NULL
    {
        x = recursive_sum(p->next);
        return x + p->data;
    }
    else
        return 0;
}

int main() {
    int A[] = {3,5,7,10,15};
    createList(A,5);
    //printf("%d ",recursive_count(first));
    printf("%d ",recursive_sum(first));
    
    return 0;
}
