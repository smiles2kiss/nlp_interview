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
    vector<int> result;
    TreeNode* pre = new TreeNode(0);
    TreeNode* temp = pre;
    void inOrder(TreeNode* root) {
        if (root != NULL) {
            inOrder(root->left);
            result.push_back(root->val);
            inOrder(root->right);
        }
    }
    TreeNode* dfs(TreeNode* root, vector<int> nums, int index) {
        int len = nums.size();
        if (index == len)
            return NULL;
        root = new TreeNode(nums[index]);
        root->right = dfs(root, nums, index + 1);
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        root = dfs(root, result, 0);
        return root;
    }
};
