#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// Data una lista restituisce la lista con i nodi invertiti a coppie
// Es. 1->2->3->4->5  Output: 2->1->4->3->5
struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode newHead;
    newHead.next = head;
    struct ListNode *prev = &newHead;
    struct ListNode *cur = head;

    while (cur != NULL && cur->next != NULL)
    {
        struct ListNode *next = cur->next;

        cur->next = next->next;
        next->next = cur;
        prev->next = next;

        prev = cur;
        cur = cur->next;
    }

    return newHead.next;
}