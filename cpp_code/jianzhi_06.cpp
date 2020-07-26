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
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        if (!head)
            return result;
        stack<int> stk;
        while (head) {
            // result.push_back(head->val);
            stk.push(head->val);
            head = head->next;
        }

        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};
