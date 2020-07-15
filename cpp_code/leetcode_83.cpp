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
        ListNode* pre = head;
        ListNode* temp = pre;
        while(head) {
            if (find(nums.begin(), nums.end(), head->val) != nums.end()) {
                temp->next = head->next;
            } else {
                nums.push_back(head->val);
                temp = head;
            }
            head = head->next;
        }
        return pre;
    }
};
