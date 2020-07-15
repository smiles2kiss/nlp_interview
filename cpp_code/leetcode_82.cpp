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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> data;
        for (int i = 0; i < nums.size(); i++) {
            if (count(nums.begin(), nums.end(), nums[i]) == 1) 
                data.push_back(nums[i]);
        }
        
        if (data.size() == 0)
            return NULL;
        ListNode* root = new ListNode(data[0]);
        ListNode* temp = root;
        for (int i = 1; i < data.size(); i++) {
            ListNode* node = new ListNode(data[i]);
            temp->next = node;
            temp = node;
        }
        return root;
    }
};
