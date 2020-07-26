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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        
        ListNode* cur = NULL;
        ListNode* pre = head;
        ListNode* temp = NULL;
        while (pre) {
            temp = head->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};
