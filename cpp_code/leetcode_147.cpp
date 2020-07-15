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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        ListNode* root = new ListNode(0);
        root->next = head;

        ListNode* pre = head;
        ListNode* cur = head->next;

        while(cur) {
            if (cur->val >= pre->val) {
                pre = pre->next;
                cur = cur->next;
            } else {
                ListNode* temp = root;
                while (temp->next->val < cur->val)
                    temp = temp->next;
                pre->next = cur->next;
                cur->next = temp->next;
                temp->next = cur;
                cur = pre->next;
            }
        }
        return root->next;
    }
};
