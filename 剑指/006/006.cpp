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
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        vector<int> v;
        if(!head) return {};
        while(head -> next) {
            s.push(head -> val);
            head = head -> next;
        }
        s.push(head -> val);
        while(!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
