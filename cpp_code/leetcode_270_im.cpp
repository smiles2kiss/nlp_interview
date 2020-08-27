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
    int closestValue(TreeNode* root, double target) {
        double closest = root->val;
        while (root) {
            if (abs(root->val - target) < abs(closest - target))
                closest = root->val;
            if (root->val > target) root = root->left;
            else root = root->right;
        }
        return closest;
    }
};
