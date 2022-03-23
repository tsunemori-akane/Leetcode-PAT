/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;

        ListNode* dummyHead1 = new ListNode(-1);
        ListNode* dummyHead2 = new ListNode(-1);
        ListNode* p1 = dummyHead1;
        ListNode* p2 = dummyHead2;
        ListNode* p = head;
        for(int i = 0; p; i ++)
            if(i % 2 == 0){
                p1->next = p;
                p = p->next;
                p1 = p1->next;
                p1->next = NULL;
            }
            else{
                p2->next = p;
                p = p->next;
                p2 = p2->next;
                p2->next = NULL;
            }

        p1->next = dummyHead2->next;
        ListNode* ret = dummyHead1->next;

        delete dummyHead1;
        delete dummyHead2;
        return ret;
    }
};
