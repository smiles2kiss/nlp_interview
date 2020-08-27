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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int len = nums.size();

        // µ¥µ÷µÝÔöÕ»
        vector<int> result(len, 0);
        stack<int> stk;
        for (int i = 0; i < len; i++) {
            while (!stk.empty() && nums.at(i) > nums.at(stk.top())) {
                int idx = stk.top();
                stk.pop();
                result[idx] = nums[i];
            }
            stk.push(i);
        }
        return result;
    }
};
