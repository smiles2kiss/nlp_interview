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
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int abs(int n) {
        return n > 0 ? n : -n;
    }
    int depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else {
            return 1 + max(depth(root->left), depth(root->right));
        }
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        else {
            if (abs(depth(root->left) - depth(root->right)) > 1)
                return false;
            else
                return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
