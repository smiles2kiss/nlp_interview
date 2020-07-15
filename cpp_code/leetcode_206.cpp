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
        
        ListNode* root = new ListNode(0);
        root->next = head;

        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur) {
            pre->next = cur->next;
            cur->next = root->next;
            root->next = cur;
            cur = pre->next;
        }
        return root->next;
    }
};
