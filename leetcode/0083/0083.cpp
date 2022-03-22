#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* p = head;
    ListNode* pre = new ListNode(-1, head);
    while(p) {
      if(pre->val != p->val) {
        pre = pre -> next;
        p = p -> next;
      } else {
        pre -> next = p -> next;
        p = p -> next;
      }
    }
    return head;
  }
};
