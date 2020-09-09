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
    TreeNode* result = NULL;
    void dfs(TreeNode* root, int val) {
        if (!root) return;
        dfs(root->left, val);
        if (root->val == val) {
            result = root;
            return;
        }
        dfs(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) { 
        dfs(root, val);
        return result;
    }
};
