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
    ListNode *detectCycle(ListNode *head) {
        // ¿ìÂýÖ¸Õë
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return NULL;

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while (slow && fast && slow->next && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow != fast) 
            return NULL;

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
