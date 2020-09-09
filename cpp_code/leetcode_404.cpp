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
    TreeNode* pre = NULL;
    int sum = 0;
    void dfs(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (pre->left == root) sum += root->val;
            return;
        }
        pre = root;
        dfs(root->left);
        dfs(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        dfs(root);
        return sum;
    }
};
