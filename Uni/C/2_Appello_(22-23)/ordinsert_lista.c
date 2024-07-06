#include <stdio.h>
#include <stdlib.h>

struct nodoLista
{
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void ord_insert(Lista **ptrPtr, int val)
{

    while (*ptrPtr != NULL && val < (*ptrPtr)->valore)
    {
        ptrPtr = &((*ptrPtr)->nextPtr);
    }

    Lista *tmpPtr = *ptrPtr;
    *ptrPtr = malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextPtr = tmpPtr;
}

void print_list(Lista *ptr)
{
    while (ptr != NULL)
    {
        printf("%d, ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void main()
{
    Lista *mylist = NULL;

    ord_insert(&mylist, 29);
    ord_insert(&mylist, 5);
    ord_insert(&mylist, 13);
    ord_insert(&mylist, 24);
    ord_insert(&mylist, 71);
    print_list(mylist);
}
