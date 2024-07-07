#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void insert(struct ListNode **ptr, int val)
{
    while (*ptr != NULL)
    {
        ptr = &((*ptr)->next);
    }
    struct ListNode *tmp = (*ptr);
    *ptr = malloc(sizeof(struct ListNode));
    (*ptr)->val = val;
    (*ptr)->next = tmp;
}

// Date due liste ordinate unirle in una sola lista ordinata
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *res = NULL;
    while (list1 != NULL || list2 != NULL)
    {
        if (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                insert(&res, list1->val);
                list1 = list1->next;
            }
            else
            {
                insert(&res, list2->val);
                list2 = list2->next;
            }
        }
        else if (list1 != NULL)
        {
            insert(&res, list1->val);
            list1 = list1->next;
        }
        else
        {
            insert(&res, list2->val);
            list2 = list2->next;
        }
    }
    return res;
}