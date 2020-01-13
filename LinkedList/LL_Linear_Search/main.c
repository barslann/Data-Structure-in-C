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

void displayList(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

struct Node* linear_search(struct Node *p,int key)
{
    
    while(p) // while(p != 0) or while(p != NULL)
    {
        if(p->data == key)
            return p; // address of the node that key found
        p=p->next;
    }
    return NULL; //key is not found
}

struct Node* recursive_linear_search(struct Node *p,int key)
{
    
    if(!p) // p == 0 or p==NULL
        return NULL;
    else
    {
        
        if(key == p->data)
            return p;
        else
            return recursive_linear_search(p->next, key);
        
    }
}

// improvement on linear search. Move the found key to the head. Next access time will be O(1)
struct Node* linear_search_move_to_head(struct Node *p,int key)
{
    struct Node *q= NULL;
    while(p) // while(p != 0) or while(p != NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p; // Key is found
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    return NULL; //key is not found
}

int main() {
    struct Node* temp;
    int A[] = {3,5,73,105,15};
    createList(A,5);
    //printf("%d ",recursive_count(first));
    printf("===Before linear search move to head function=== \n");
    displayList(first);
    temp = linear_search_move_to_head(first, 105);
    if (temp) {
        printf("Key is found %d\n",temp->data);
    }else
        printf("Key is not found\n");
    printf("===After linear search move to head function===\n");
    displayList(first);
    
    return 0;
}
