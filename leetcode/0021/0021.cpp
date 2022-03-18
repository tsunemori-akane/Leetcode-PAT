#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    ListNode* h1 = list1;
    ListNode* h2 = list2;
    while(h1 != NULL && h2 != NULL) {
      if(h1->val > h2->val) {
        p->next = h2;
        h2 = h2->next;
      } else {
        p->next = h1;
        h1 = h1->next;
      }
      p = p -> next;
    }

    if(h1 == NULL) {
      p -> next = h2;
    } else if(h2 == NULL) {
      p -> next = h1;
    }
    return dummy->next;
  }
};

int main() {

  return 0
}
