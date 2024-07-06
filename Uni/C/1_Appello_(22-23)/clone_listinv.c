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
    while ((*ptrPtr) != NULL)
    {
        ptrPtr = &((*ptrPtr)->nextPtr);
    }
    Lista *tmp = (*ptrPtr);
    (*ptrPtr) = malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextPtr = tmp;
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

void clone_list(Lista *scrPtr, Lista **destPtr)
{
    if (scrPtr->nextPtr != NULL)
    {
        scrPtr = scrPtr->nextPtr;
        clone_list(scrPtr, &(*destPtr));
    }
    suf_insert(&(*destPtr), scrPtr->valore);
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

    Lista *clonelist = NULL;
    clone_list(mylist, &clonelist);
    print_list(clonelist);
}
