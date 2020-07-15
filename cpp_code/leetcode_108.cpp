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
    TreeNode* convert(vector<int> nums, int start, int end) {
        if (start > end)
            return NULL;
        int mid = (start + end + 1) / 2;
        int root_val = nums[mid];
        TreeNode* root = new TreeNode(root_val);
        root->left = convert(nums, start, mid - 1);
        root->right = convert(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size() - 1);
    }
};
