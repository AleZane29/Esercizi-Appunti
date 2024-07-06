#include <stdio.h>
#include <stdlib.h>

struct nodoLista
{
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void suf_insert(Lista **ptrPtr, int val)
{
    while (*ptrPtr != NULL)
    {
        ptrPtr = &((*ptrPtr)->nextPtr);
    }
    Lista *tmpPtr = *ptrPtr;
    *ptrPtr = malloc(sizeof(Lista));
    (*ptrPtr)->nextPtr = tmpPtr;
    (*ptrPtr)->valore = val;
}

void print_list(Lista *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

void clone_invlist(Lista *scrPtr, Lista **destPtr)
{
    while (scrPtr != NULL)
    {
        Lista *tmpPtr = *destPtr;
        *destPtr = malloc(sizeof(Lista));
        (*destPtr)->nextPtr = tmpPtr;
        (*destPtr)->valore = scrPtr->valore;
        scrPtr = scrPtr->nextPtr;
    }
}

void clone_invlist_ric(Lista *scrPtr, Lista **destPtr)
{
    if (scrPtr != NULL)
    {
        Lista *tmpPtr = *destPtr;
        *destPtr = malloc(sizeof(Lista));
        (*destPtr)->nextPtr = tmpPtr;
        (*destPtr)->valore = scrPtr->valore;
        scrPtr = scrPtr->nextPtr;
        clone_invlist_ric(scrPtr, &(*destPtr));
    }
}

void main()
{
    Lista *mylist = NULL;

    suf_insert(&mylist, 29);
    suf_insert(&mylist, 5);
    suf_insert(&mylist, 13);
    suf_insert(&mylist, 24);
    print_list(mylist);

    Lista *myinvlist = NULL;
    clone_invlist_ric(mylist, &myinvlist);
    print_list(myinvlist);
}
