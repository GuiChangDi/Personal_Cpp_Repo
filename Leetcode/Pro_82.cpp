/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 *  leaving only distinct numbers from the original list.
 * */
#define NULL 0
#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p,*q,*temp;
    p = head;
    temp = p;
    q = head->next;
    while(p->next != NULL)
    {
        if(p ->val == q->val)
        {
            temp = p->next;
            p->next = q->next;
            free(temp);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}