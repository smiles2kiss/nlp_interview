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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;

        ListNode* temp = head;
        int len = 0;
        while(temp) {
            len = len + 1;
            temp = temp->next;
        }
        k = k % len;
        if (k == 0)
            return head;

        int step = len - k;
        ListNode* pre = head;
        temp = head;
        temp = temp->next;
        for (int i = 1; i < step; i++) {
            pre = pre->next;
            temp = temp->next;
        }
        ListNode* temp1 = temp;
        while(temp1->next) {
            temp1 = temp1->next;
        }
        pre->next = NULL;
        temp1->next = head;
        return temp;
    }
};
