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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* pre  = root;

        while (head) {
            if (head->val == val) {
                pre->next = head->next;
                break;
            }
            pre = pre->next;
            head = head->next;
        }
        return root->next;
    }
};
