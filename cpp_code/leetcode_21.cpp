/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Í·½Úµã
        ListNode* l3 = new ListNode(0);
        l3->next = NULL;
        ListNode* head = l3;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                ListNode* temp = new ListNode(l2->val);
                head->next = temp;
                head = temp;
                l2 = l2->next;
            } else {
                ListNode* temp = new ListNode(l1->val);
                head->next = temp;
                head = temp;
                l1 = l1->next;
            }
        }
        while (l1) {
            ListNode* temp = new ListNode(l1->val);
            head->next = temp;
            head = temp;
            l1 = l1->next;
        }
        while (l2) {
            ListNode* temp = new ListNode(l2->val);
            head->next = temp;
            head = temp;
            l2 = l2->next;
        }
        return l3->next;
    }
};
