#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next; // self referential pointer
}*Head;

void create(int A[], int n)
{
    int i;
    struct Node *t=NULL,*last=NULL;
    Head = (struct Node*)malloc(sizeof(struct Node));// create first node and make HEAD point on that node
    Head->data = A[0];
    Head->next=Head;
    last=Head;
    
    for (i=1; i<n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data =A[i];
        t->next = last->next;
        last->next =t;
        last = t;
    }
}

void Display(struct Node *h){
   
    do {
        printf("%d ",h->data);
        h=h->next;
    } while (h!=Head);
    printf("\n");
}

int Length(struct Node *p)
{
    int len=0;
    do {
        len++;
        p=p->next;
    } while (p!=Head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    
    if (index < 0 || index > Length(Head)) {
        return;
    }
    
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(Head == NULL)
        {
            Head= t;
            Head->next = Head;
            
        }
        else
        {
            while(p->next != Head) p = p->next;
            p->next=t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (i=0; i<index-1; i++) p=p->next; // p will bemoving to the nodes and it will be stopping at the node where we want to insert
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
        
    }
}

int Delete(struct Node *p,int index)
{
    struct Node *q;
    int i,x; // for traversing the linked list
    
    if (index < 0 || index > Length(Head)) {
        return -1;
    }
    
    if (index == 1) {
        while(p->next != Head) p=p->next;
        x = Head->data;
        if(Head == p) // check if it is only node in the ll
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for (i=0; i< index -2 ; i++) {
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x=q->data;
        free(q);
    }
    return x;
}
void RecursiveDisplay(struct Node *h)
{
    static int flag = 0;
    if (h!=Head || flag==0) {
        flag=1;
        printf("%d ",h->data);
        RecursiveDisplay(h->next);
    }
    flag=0;
}

int main(int argc, const char * argv[]) {
    int A[] = {2,3,4,5,6};
    create(A, 5);
// Insert(Head, 0, 10);
    Delete(Head, 2);
    Display(Head);
    return 0;
}
