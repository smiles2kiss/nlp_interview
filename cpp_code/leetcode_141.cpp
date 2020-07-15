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
    bool hasCycle(ListNode *head) {
        // ¿ìÂıÖ¸Õë
        if (head == NULL)
            return false;
        
        ListNode* pre = head;
        ListNode* cur = head;
        while(cur && pre && pre->next) {
            cur = cur->next;
            pre = pre->next->next;
            if (cur == pre) {
                return true;
            }
        }
        return false;
    }
};
