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
    void inOrder(TreeNode* root) {
        if (root != NULL) {
            inOrder(root->left);
            result.push_back(root->val);
            inOrder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return result;
    }
};
