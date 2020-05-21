#include <iostream>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
Input example:
  [2,4,3] -> 342
  [5,6,4] -> 465
Output should be:
  [7,0,8] -> 807
*/

class Solution{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* l3 = NULL;
    ListNode** p3 = &l3;
    int sum = 0;

    while( l1 != NULL || l2 != NULL || sum > 0){
      if ( l1 != NULL){
        sum += l1->val;
        l1 = l1->next;
      }
      if ( l2 != NULL){
        sum += l2->val;
        l2 = l2->next;
      }
      
      *p3 = new ListNode(sum % 10);
      sum /= 10;
      p3 = &((*p3)->next);
    }
    return l3;
  }
};