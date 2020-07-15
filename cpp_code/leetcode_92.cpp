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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* root = new ListNode(0);
        root->next = head;

        ListNode* small_before = root;
        ListNode* pre = root;
        ListNode* cur = head;
        ListNode* revert_start = head;
        ListNode* temp = head;
        int pos = 0;
        while(temp) {
            pos = pos + 1;
            
            if (pos < m) {
                small_before = small_before->next;
                pre = pre->next;
                cur = cur->next;
                revert_start = revert_start->next;
            } else if (pos == m) {
                pre = pre->next;
                cur = cur->next;
            } else if (pos > m && pos < n) {
                pre->next = cur->next;
                cur->next = revert_start;
                small_before->next = cur;
                revert_start = cur;
                cur = pre->next;
            } else if (pos == n) {
                pre->next = cur->next;
                cur->next = revert_start;
                small_before->next = cur;
                revert_start = cur;
                cur = pre->next;
                break;
            }
            temp = temp->next;
        }
        return root->next;
    }
};
