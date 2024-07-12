#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextPtr;
};

typedef struct node List;

// esempio lista: 17 -> 29 -> 93

void init(List **ptrPtr);
// ritorna 1 se vuota; 0 altrimenti
int isempty(List *ptr);
void print_list(List *ptr);

void pre_insert(List **ptr, int val);
void wrong_insert(List *ptr, int val);
void suf_insert(List **ptr, int val);

void ord_insert(List **ptr, int val);

// versione alternativa con return
List *pre_insert_bis(List *ptr, int val);

// funzioni ricorsive
void print_list_rec(List *ptr);
void suf_insert_rec(List **ptr, int val);

void clone_list(List *scrPtr, List **destrPtr);

List *remove_node(List *ptr, int pos);

// stack (pila) e queue (coda)
void push(List **ptr, int val);
void pop(List **ptr);

int main()
{

    List *mialista;
    init(&mialista);

    pre_insert(&mialista, 4);

    pre_insert(&mialista, 3);
    pre_insert(&mialista, 2);
    pre_insert(&mialista, 1);

    suf_insert(&mialista, 6);
    mialista = pre_insert_bis(mialista, 0);
    suf_insert_rec(&mialista, 7);
    ord_insert(&mialista, 2);
    ord_insert(&mialista, 5);

    print_list(mialista);
    printf("\n");

    List *cloneList;
    init(&cloneList);
    clone_list(mialista, &cloneList);
    print_list(cloneList);
    printf("\n");

    mialista = remove_node(mialista, 0);
    print_list(mialista);
    printf("\n");

    return 0;
}

void init(List **ptrPtr)
{
    *ptrPtr = NULL;
}

int isempty(List *ptr)
{
    return ptr == NULL;
}

void pre_insert(List **ptr, int val)
{
    List *tmp = (*ptr);
    *ptr = malloc(sizeof(List));
    (*ptr)->value = val;
    (*ptr)->nextPtr = tmp;
}

void suf_insert(List **ptr, int val)
{
    while (*ptr != NULL)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void print_list(List *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->value);
        ptr = ptr->nextPtr;
    }
}

// liste: funzioni viste nella lezione n.2:

List *pre_insert_bis(List *ptr, int val)
{
    List *tmp = ptr;
    ptr = malloc(sizeof(List));
    ptr->value = val;
    ptr->nextPtr = tmp;
    return ptr;
}

void ord_insert(List **ptr, int val)
{
    while ((*ptr) != NULL && val > (*ptr)->value)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void print_list_rec(List *ptr)
{
    if (ptr != NULL)
    {
        printf("%d", ptr->value);
        print_list(ptr->nextPtr);
    }
}

void suf_insert_rec(List **ptr, int val)
{
    if (*ptr != NULL)
    {
        suf_insert_rec(&(*ptr)->nextPtr, val);
    }
    else
    {
        pre_insert(ptr, val);
    }
}

void clone_list(List *scrPtr, List **destPtr)
{
    while (scrPtr != NULL)
    {
        suf_insert(destPtr, scrPtr->value);
        scrPtr = scrPtr->nextPtr;
    }
}

List *remove_node(List *ptr, int pos)
{
    if (ptr == NULL)
    {
        return ptr;
    }
    if (pos == 0)
    {
        struct List *next = ptr->nextPtr;
        free(ptr);
        return next;
    }
    List *current = ptr;
    while (pos != 1)
    {
        current = current->nextPtr;
        pos--;
    }
    List *next = current->nextPtr->nextPtr;
    free(current->nextPtr);
    current->nextPtr = next;
    return ptr;
}

// pila: push e pop

void push(List **ptr, int val)
{
    // è la suf_insert già sviluppata...
    while (*ptr != NULL)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void pop(List **ptr)
{

    // verifica se lista vuota
    if (isempty(*ptr))
    {
        // if(*ptr == NULL) {
        printf("La lista è vuota!\n");
    }
    else if ((*ptr)->nextPtr == NULL)
    {
        //*ptr = NULL;
        free(*ptr);
    }
    else
    {
        List *tmpPtr, *current = *ptr;

        while (current->nextPtr != NULL)
        {
            tmpPtr = current;
            current = current->nextPtr;
        }
        // cancella elemento in coda
        tmpPtr->nextPtr = NULL;
        free(current);
    }
}