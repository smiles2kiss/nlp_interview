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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;

        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count = count + 1;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < count / 2; i++) {
            temp = temp->next;
        }
        return temp;
    }
};
