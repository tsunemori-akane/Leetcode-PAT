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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(-1, head);
      ListNode* p1 = head;
      ListNode* p2 = head;
      ListNode* p3 = dummy;
      for(int i = 0; i < n; i++) {
        p1 = p1->next;
      }
      while(p1) {
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
      }
      p3->next = p2->next;
      return dummy->next;
    }
};
