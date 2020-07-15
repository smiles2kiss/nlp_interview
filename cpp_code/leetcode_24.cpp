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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        
        ListNode* result = head;

        ListNode* pre = head;
        head = head->next;
        int temp = pre->val;
        pre->val = head->val;
        head->val = temp;

        while (pre->next->next && head->next->next) {
            head = head->next;
            pre = pre->next;
            head = head->next;
            pre = pre->next;

            int temp = pre->val;
            pre->val = head->val;
            head->val = temp;
        }
        
        return result;
    }
};
