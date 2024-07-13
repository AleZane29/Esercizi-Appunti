#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextPtr;
};

typedef struct node List;

// Data una lista rimuovere l'ennesimo nodo dalla fine
List *removeNthFromEnd(List *head, int n)
{
    int cont = 0;
    List *count = head;
    while (count != NULL)
    {
        cont++;
        count = count->nextPtr;
    }
    n = cont - n;
    if (head == NULL)
    {
        return NULL;
    }
    if (n == 0)
    {
        List *tmp = head->nextPtr;
        free(head);
        return tmp;
    }
    List *current = head;
    while (n != 1)
    {
        current = current->nextPtr;
        n--;
    }
    List *nextPtr = current->nextPtr->nextPtr;
    free(current->nextPtr);
    current->nextPtr = nextPtr;
    return head;
}