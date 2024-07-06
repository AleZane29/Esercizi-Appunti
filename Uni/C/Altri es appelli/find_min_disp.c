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

Lista *first_odd(Lista *list)
{
    Lista *num = NULL;
    while (list != NULL)
    {
        if (list->valore % 2 != 0 && (num == NULL || list->valore < num->valore))
        {
            num = list;
        }
        list = list->nextPtr;
    }
    return num;
}

Lista *first_odd_ric(Lista *list)
{
    Lista *num = NULL;
    if (list != NULL)
    {
        num = first_odd_ric(list->nextPtr);
        if (list->valore % 2 != 0 && (num == NULL || list->valore < num->valore))
        {
            num = list;
        }
    }
    return num;
}

void main()
{
    Lista *mylist = NULL;

    suf_insert(&mylist, 12);
    suf_insert(&mylist, 31);
    suf_insert(&mylist, 13);
    suf_insert(&mylist, 267);
    printf("Min dispari: %d\n", first_odd(mylist)->valore);
    printf("Min dispari: %d", first_odd_ric(mylist)->valore);
}
