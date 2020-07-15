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
    void deleteNode(ListNode* node) {
        ListNode* pre = node;
        node = node->next;
        int temp = pre->val;
        pre->val = node->val;
        node->val = temp;
        while(node->next) {
            node = node->next;
            pre = pre->next;
            int temp = pre->val;
            pre->val = node->val;
            node->val = temp;
        }
        pre->next = NULL;
    }
};
