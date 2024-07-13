#include <stdio.h>
#include <stdlib.h>

#define COUNT 8

struct btree
{
    int value;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void init(BST **ptrPtr);
int isempty(BST *ptr);
int search(BST *ptr, int val);
int search_rec(BST *ptr, int val);
void print_rec(BST *ptr);
void ordinsert_rec(BST **ptrPtr, int val);
int isBST(BST *ptr);

int get_right_min(BST *ptr);
BST *delete_node(BST *ptr, int val);

// funzioni di "servizio" (per visualizzazione)

int main(void)
{
    BST *albero;
    init(&albero);

    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 1);
    ordinsert_rec(&albero, 0);
    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 9);
    ordinsert_rec(&albero, 5);
    print_rec(albero);
    printf("\n");

    int v = 1;
    printf("L'albero contiene il valore %d? %d\n", v, search(albero, v));
    printf("L'albero e' BST? %d\n", isBST(albero));

    albero = delete_node(albero, 2);
    print_rec(albero);
    printf("\n");

    return 0;
}

void init(BST **ptrPtr)
{
    *ptrPtr = NULL;
}

// restituisce 1 se l'albero è vuoto, 0 altrimenti
int isempty(BST *ptr)
{
    return ptr == NULL;
}

// restituisce 1 se l'albero è BST, 0 altrimenti
int isBST(BST *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->leftPtr != NULL)
        {
            if (ptr->value >= ptr->leftPtr->value)
            {
                if (isBST(ptr->leftPtr) == 0)
                {
                    return 0;
                };
            }
            else
            {
                return 0;
            }
        }
        if (ptr->rightPtr != NULL)
        {
            if (ptr->value < ptr->rightPtr->value)
            {
                if (isBST(ptr->rightPtr) == 0)
                {
                    return 0;
                };
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

int get_right_min(BST *ptr)
{
    while (ptr->leftPtr != NULL)
    {
        ptr = ptr->leftPtr;
    }
    return ptr->value;
}

BST *delete_node(BST *ptr, int val)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    if (val > ptr->value)
    {
        ptr->rightPtr = delete_node(ptr->rightPtr, val);
    }
    else if (val < ptr->value)
    {
        ptr->leftPtr = delete_node(ptr->leftPtr, val);
    }
    else
    {
        if (ptr->leftPtr == NULL && ptr->rightPtr == NULL)
        {
            free(ptr);
            return NULL;
        }
        else if (ptr->rightPtr == NULL)
        {
            BST *tmp = ptr->leftPtr;
            free(ptr);
            return tmp;
        }
        else if (ptr->leftPtr == NULL)
        {
            BST *tmp = ptr->rightPtr;
            free(ptr);
            return tmp;
        }
        else
        {
            int min = get_right_min(ptr->rightPtr);
            ptr->value = min;
            ptr->rightPtr = delete_node(ptr->rightPtr, min);
        }
    }
    return ptr;
}

// visita ricorsiva
void print_rec(BST *ptr)
{
    if (ptr != NULL)
    {
        print_rec(ptr->leftPtr);
        printf("%d ", ptr->value);
        print_rec(ptr->rightPtr);
    }
}

// restituisce 1 se l'albero contiene l'elemento val, 0 altrimenti
int search(BST *ptr, int val)
{
    while (ptr != NULL)
    {
        if (ptr->value == val)
        {
            return 1;
        }
        else if (ptr->value > val)
        {
            ptr = ptr->leftPtr;
        }
        else if (ptr->value < val)
        {
            ptr = ptr->rightPtr;
        }
    }
    return 0;
}

// restituisce 1 se l'albero contiene l'elemento val, 0 altrimenti
int search_rec(BST *ptr, int val)
{
    if (ptr != NULL)
    {
        if (val > ptr->value)
        {
            return search_rec(ptr->rightPtr, val);
        }
        else if (val < ptr->value)
        {
            return search_rec(ptr->leftPtr, val);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// inserimento in ordine (con ricorsione)
void ordinsert_rec(BST **ptrPtr, int val)
{
    if ((*ptrPtr) != NULL)
    {
        if (val > (*ptrPtr)->value)
        {
            ordinsert_rec(&((*ptrPtr)->rightPtr), val);
        }
        else
        {
            ordinsert_rec(&((*ptrPtr)->leftPtr), val);
        }
    }
    else
    {
        (*ptrPtr) = (BST *)malloc(sizeof(BST));
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
        (*ptrPtr)->value = val;
    }
}
