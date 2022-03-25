#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {} 
  ListNode(int x, ListNode* next): val(x), next(nullptr) {}
}

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if(head == NULL ||head->next == NULL) {
      return head;
    }
    ListNode* f = head;
    ListNode* s = head;
    while(f->next != NULL && f->next->next != NULL) {
      f = f->next->next;
      s = s->next;
    }
    ListNode* temp = s->next;
    s->next = NULL;
    ListNode* left = sortList(head);
    ListNode* right = sortList(temp);
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    while(left != NULL && right != NULL) {
      if(left->val > right->val) {
        pre->next = right;
        right = right->next;
      } else {
        pre->next = left;
        left = left->next;
      }
      pre = pre->next;
    }
    pre->next = left == NULL ? right : left;
    return dummy->next; 
  }
};
