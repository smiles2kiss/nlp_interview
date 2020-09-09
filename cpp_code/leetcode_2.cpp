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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* res = new ListNode(0);
        ListNode* temp3 = res;

        int add = 0, sum = 0;
        while (temp1 && temp2) {
            sum = temp1->val + temp2->val + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            temp3->next = node;
            temp3 = node;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1) {
            sum = temp1->val + add;
            add = sum / 10;
            sum = sum % 10;
            
            ListNode* node = new ListNode(sum);
            temp3->next = node;
            temp3 = node;

            temp1 = temp1->next;
        }

        while (temp2) {
            sum = temp2->val + add;
            add = sum / 10;
            sum = sum % 10;

            ListNode* node = new ListNode(sum);
            temp3->next = node;
            temp3 = node;

            temp2 = temp2->next;
        }

        if (add == 1) {
            ListNode* node = new ListNode(add);
            temp3->next = node;
            temp3 = node;
        }
        return res->next;
    }
};
