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
    vector<int> nums;
    void inOrder(TreeNode* root) {
        if (root) {
            inOrder(root->left);
            nums.push_back(root->val);
            inOrder(root->right);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        inOrder(root);
        int len = nums.size();
        int idx = len - k;
        return nums[idx];
    }
};
