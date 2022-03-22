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
    bool isPalindrome(ListNode* head) {
      ListNode* g = head;
      ListNode* t = head;
      while (t->next && t->next->next) {
          t = t->next->next;
          g = g->next;
      }
      ListNode* r = reverse(g->next);
      while(r) {
        if(r->val != head->val) return false;
        r = r->next;
        head = head->next;
      }
      return true;
    }

    ListNode* reverse(ListNode* head) {
      ListNode* p = head;
      ListNode* pre = NULL;
      while(p) {
        ListNode* next = p->next;
        p->next = pre;
        pre = p;
        p = next;
      }
      return pre;
    }
};
