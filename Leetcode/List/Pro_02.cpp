#include <iostream>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* l3 = new ListNode(0);
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* p3 = l3;
    bool flag = 0;
    int sum = 0;
    while(p1 != NULL || p2 != NULL){
      sum = 0;
      if (p1->next != NULL){
        sum += p1->val;
        p1 = p1->next;
      }

      if (p2->next != NULL){
        sum += p2->val;
        p2 = p2->next;
      }

      if(flag) sum++;
      p3->next = new ListNode(sum%10);
      p3 = p3->next;
      flag = (sum>=10)? true : false;
    }
    if(flag)  p3->next = new ListNode(1);
    return l3;
  }
};