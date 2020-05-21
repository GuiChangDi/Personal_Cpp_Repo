//Remove Nth Node From End of List
#include <iostream>

 struct ListNode {
     int val;
    struct ListNode *next;
 };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *temp,*q,*p;
    p = head;
    q = head;
    int i = 0;
    while(p->next)
    {
        p = p->next;
        i++;
        if(i>n)
            q = q->next;
    }
    temp = q->next;
    q->next = temp->next;
    free(temp);
    return head;
}