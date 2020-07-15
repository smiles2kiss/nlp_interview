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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            while (head) {
                nums.push_back(head->val);
                head = head->next;
            }
        }
        if (nums.size() == 0) 
            return NULL;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        ListNode* result = new ListNode(nums[0]);
        ListNode* temp = result;
        for (int i = 1; i < nums.size(); i++) {
            ListNode* node = new ListNode(nums[i]);
            temp->next = node;
            temp = node;
        }
        return result;
    }
};
