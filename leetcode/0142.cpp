/**
 * https://en.wikipedia.org/wiki/Cycle_detection
 * 初始状态下,起点S,现设两个指针t和h,都指向S...t每前进1步，h前进2步
 * @求解环路的长度：
 * 上述算法刚判断出存在环C时，显然t和h位于同一节点，设其为节点M。
 * 显然，仅需令h不动，而t不断推进，最终又会返回节点M，统计这一次t推进的步数，显然这就是环C的长度。
 * @求解环路的起点：
 * 假设出发点到环起点距离m,环周长n,慢指针与快指针相遇时,相遇点距环起点k.
 * 慢指针移动距离i=m+a*n+k,快指针移动距离2i=m+b*n+k,b和a为快慢指针相遇时绕的圈数
 * 将一个指针移到出发起点S，另一个指针仍呆在相遇节点M处两者同时移动
 * 每次都只移动一步。当第一个指针前进了m，即到达环起点时，另一个指针也前进了m到达环起点
 * k+m=i-a*n 又因为i=(m+b*n+k)-(m+a*n+k)=(b-a)*n为环周长整数倍则k+m为n的整数倍
 * 故相遇点为环起点
 */
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL ||head -> next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            if(fast->next == NULL || fast->next->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        fast = head;
        while(fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};
