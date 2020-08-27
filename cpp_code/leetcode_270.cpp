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
    double min;
    double result;
    void preOrder(TreeNode* root, double target) {
        if (!root) return;
        if (abs(root->val - target) < min) {
            result = root->val;
            min = abs(root->val - target);
        }
        preOrder(root->left, target);
        preOrder(root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        min = abs(root->val - target);
        result = root->val;
        preOrder(root, target);
        return result;
    }
};
