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
    int min(int a, int b) {
        return a < b ? a : b;
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        else if (root->left != NULL && root->right == NULL) {
            return minDepth(root->left) + 1;
        }
        else if (root->left == NULL && root->right != NULL) {
            return minDepth(root->right) + 1;
        }
        else {
            return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
        } 
    }
};
