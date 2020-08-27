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

        vector<int> result(len, 0);
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[j] > nums[i]) {
                    result[i] = nums[j];
                    break;
                }
            }
        }
        return result;
    }
};
