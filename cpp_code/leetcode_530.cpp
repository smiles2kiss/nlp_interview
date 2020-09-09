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
    int mmin = INT_MAX;
    int pre = INT_MAX;
    void preOrder(TreeNode* root) {
        if (!root) return;
        preOrder(root->left);
        mmin = min(mmin, abs(root->val - pre));
        pre = root->val;
        preOrder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        preOrder(root);
        return mmin;
    }
};
