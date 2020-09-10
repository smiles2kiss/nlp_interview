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
    TreeNode* pre = NULL;
    void dfs(TreeNode* root, int val) {
        if (!root) return;
        pre = root;
        if (root->val > val) {
            dfs(root->left, val);
            return;
        }
        else if (root->val < val) {
            dfs(root->right, val);
            return;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        dfs(root, val);
        TreeNode* node = new TreeNode(val);
        if (!root) return node;
        if (pre->val > val) pre->left = node;
        if (pre->val < val) pre->right = node;
        return root;
    }
};
