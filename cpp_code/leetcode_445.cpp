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
        if (!l1) return l2;
        if (!l2) return l1;

        stack<int> stk1;
        stack<int> stk2;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* res = new ListNode(0);
        ListNode* temp = res;

        int add = 0, sum = 0;
        while (!stk1.empty() && !stk2.empty()) {
            sum = stk1.top() + stk2.top() + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            node->next = temp->next;
            temp->next = node;
            stk1.pop();
            stk2.pop();
        }
        while (!stk1.empty()) {
            sum = stk1.top() + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            node->next = temp->next;
            temp->next = node;
            stk1.pop();
        }
        while (!stk2.empty()) {
            sum = stk2.top() + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            node->next = temp->next;
            temp->next = node;
            stk2.pop();
        }
        if (add == 1) {
            ListNode* node = new ListNode(add);
            node->next = temp->next;
            temp->next = node;
        }
        return res->next;
    }
};
