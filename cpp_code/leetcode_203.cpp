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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;

        ListNode* root = new ListNode(val);
        root->next = head;
        ListNode* pre = root;
        ListNode* cur = head;

        while(cur) {
            if (cur->val != val) {
                pre = pre->next;
                cur = cur->next;
            } else {
                pre->next = cur->next;
                cur = pre->next;
            }
        }
        return root->next;
    }
};
