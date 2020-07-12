
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive Algorithm 
class Solution {
public:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else
            return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
};

// Non-Recursive Algorithm

