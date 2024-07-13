#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextPtr;
};

typedef struct node List;

void pre_insert(List **ptr, int val)
{
    List *tmp = (*ptr);
    (*ptr) = malloc(sizeof(List));
    (*ptr)->nextPtr = tmp;
    (*ptr)->value = val;
}

void suf_insert(List **ptr, int val)
{
    while (*ptr != NULL)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

List *remove_node(List *ptr, int pos)
{
    if (ptr == NULL)
    {
        return ptr;
    }
    if (pos == 0)
    {
        List *next = ptr->nextPtr;
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

void print_list(List *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->nextPtr;
    }
}

List *preleva(List **L, int *a, int dim)
{
    List *res = NULL;
    List *tmp = *L;
    int indexL = 0;
    for (int i = 0; i < dim && tmp != NULL; i++)
    {
        while (indexL < a[i])
        {
            tmp = tmp->nextPtr;
            indexL++;
        }

        printf("i:%d, calc-i:%d, val:%d\n", indexL, a[i] - i, tmp->value);
        suf_insert(&res, tmp->value);
        tmp = tmp->nextPtr;
        indexL++;
        (*L) = remove_node(*L, a[i] - i);
    }
    return res;
}

int main()
{

    List *mialista = NULL;
    pre_insert(&mialista, 6);
    pre_insert(&mialista, 5);
    pre_insert(&mialista, 4);
    pre_insert(&mialista, 3);
    pre_insert(&mialista, 2);
    pre_insert(&mialista, 1);

    print_list(mialista);

    printf("\n");

    int a[] = {0, 2, 5};
    // Ultimo  numero dimensione array
    List *list2 = preleva(&mialista, a, 3);

    print_list(mialista);

    printf("\n");
    print_list(list2);
    printf("\n");
}