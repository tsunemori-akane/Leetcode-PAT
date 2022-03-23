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
        if (!head) return head;
        ListNode* evenHead = head->next;        //奇头是head，偶头就是head->next
        ListNode* odd = head, *even = evenHead; //分别定义奇偶尾指针

        while (even && even->next)
        {
            odd = odd->next = even->next;       //等于 odd->next = even->next; odd = odd->next;
            even = even->next = odd->next;
        }

        odd->next = evenHead;

        return head;
    }
};
