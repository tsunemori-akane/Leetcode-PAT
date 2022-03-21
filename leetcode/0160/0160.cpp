/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB) {
          if(a == 2 || b == 2) return NULL;
          if(pA == NULL) {
            a += 1;
            pA = headB;
          } else pA = pA->next;

          if(pB == NULL) {
            b += 1;
            pB = headA;
          } else pB = pB->next;
        }
        return pA;
    }
};
