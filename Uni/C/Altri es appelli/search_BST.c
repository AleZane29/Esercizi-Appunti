#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void print_rec(BST *ptr)
{
    if (ptr != NULL)
    {
        print_rec(ptr->leftPtr);
        printf("%d", ptr->valore);
        print_rec(ptr->rightPtr);
    }
}

void ordinsert(BST **ptrPtr, int val)
{
    if ((*ptrPtr) != NULL)
    {
        if (val <= (*ptrPtr)->valore)
        {
            ordinsert(&((*ptrPtr)->leftPtr), val);
        }
        else
        {
            ordinsert(&((*ptrPtr)->rightPtr), val);
        }
    }
    else
    {
        (*ptrPtr) = (BST *)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->rightPtr = NULL;
        (*ptrPtr)->leftPtr = NULL;
    }
}

int search_BST(BST *ptr, int val)
{
    if (ptr == NULL)
    {
        return 0;
    }
    if (val > ptr->valore)
    {
        return search_BST(ptr->rightPtr, val);
    }
    if (val < ptr->valore)
    {
        return search_BST(ptr->leftPtr, val);
    }
    return 1;
}

int main()
{
    BST *albero = NULL;
    ordinsert(&albero, 5);
    ordinsert(&albero, 3);
    ordinsert(&albero, 7);
    ordinsert(&albero, 1);
    ordinsert(&albero, 4);
    ordinsert(&albero, 7);
    ordinsert(&albero, 8);
    ordinsert(&albero, 6);
    print_rec(albero);

    printf("\nVal esistente: %d", search_BST(albero, 10));

    return 0;
}
