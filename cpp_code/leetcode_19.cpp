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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        ListNode* parent = new ListNode(n);
        parent->next = head;

        ListNode* temp = head;
        int list_len = 0;
        while(temp != NULL) {
            temp = temp->next;
            list_len = list_len + 1;
        }

        temp = parent;
        for (int i = 0; i < list_len - n; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return parent->next;
    }
};
