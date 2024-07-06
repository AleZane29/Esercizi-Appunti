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

BST *min_right_ptr(BST *root)
{
    BST *tmp = root;
    while (tmp->leftPtr != NULL)
    {
        tmp = tmp->leftPtr;
    }
    return tmp;
}

void delete_node_rec(BST **ptrPtr)
{
    BST *currPtr = *ptrPtr;
    if (currPtr->leftPtr == NULL && currPtr->rightPtr == NULL)
    {
        free(currPtr);
        *ptrPtr = NULL;
    }
    else if (currPtr->leftPtr == NULL)
    {
        *ptrPtr = currPtr->rightPtr;
        free(currPtr);
    }
    else if (currPtr->rightPtr == NULL)
    {
        *ptrPtr = currPtr->leftPtr;
        free(currPtr);
    }
    else
    {
        BST *min = min_right_ptr(currPtr->rightPtr);
        currPtr->valore = min->valore;
        delete_node_rec(&(currPtr->rightPtr));
    }
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

    printf("\n");

    printf("valore: %d\n", ((albero->leftPtr)->valore));
    delete_node_rec(&(albero->leftPtr));
    print_rec(albero);

    return 0;
}
