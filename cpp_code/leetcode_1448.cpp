/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, int max_value) {
        if (!root) return;
        if (root->val >= max_value) count++;
        max_value = max(max_value, root->val);
        dfs(root->left, max_value);
        dfs(root->right, max_value);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};
