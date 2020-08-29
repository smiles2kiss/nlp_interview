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
    int sum = 0;
    void Order(TreeNode* root) {
        if (root == NULL) return;
        Order(root->right);
        sum += root->val;
        root->val = sum;
        Order(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        Order(root);
        return root;
    }
};
