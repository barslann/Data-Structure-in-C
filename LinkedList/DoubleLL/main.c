#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;
    
    for (i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = last->next;
        t->prev = last;
        last->prev = t;
        last=t;
        
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    
    return 0;
}