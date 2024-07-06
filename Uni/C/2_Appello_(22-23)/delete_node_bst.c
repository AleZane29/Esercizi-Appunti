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

int min_right_ptr(BST *root)
{
    BST *tmp = root;
    while (tmp->leftPtr != NULL)
    {
        tmp = tmp->leftPtr;
    }
    return tmp->valore;
}

BST *remove_node(BST *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (val > root->valore)
    {
        root->rightPtr = remove_node(root->rightPtr, val);
    }
    else if (val < root->valore)
    {
        root->leftPtr = remove_node(root->leftPtr, val);
    }
    else
    {
        if (root->rightPtr == NULL && root->leftPtr == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->leftPtr == NULL)
        {
            BST *tmp = root->rightPtr;
            free(root);
            return tmp;
        }
        else if (root->rightPtr == NULL)
        {
            BST *tmp = root->leftPtr;
            free(root);
            return tmp;
        }
        else
        {
            int min = min_right_ptr(root->rightPtr);
            root->valore = min;
            root->rightPtr = remove_node(root->rightPtr, min);
        }
    }
    return root;
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
    albero = remove_node(albero, 6);
    print_rec(albero);

    return 0;
}
