/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inOrder(vector<int> nums, int left, int right) {
        if (left <= right) {
            int mid = (left + right) / 2;
            TreeNode* node = new TreeNode(nums[mid]);

            if (left == right) 
                return node;

            node->left  = inOrder(nums, left, mid - 1);
            node->right = inOrder(nums, mid + 1, right);
            return node;
        } else {
            return NULL;
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = nums.size() - 1;
        TreeNode* root = inOrder(nums, left, right);
        return root;
    }
};
