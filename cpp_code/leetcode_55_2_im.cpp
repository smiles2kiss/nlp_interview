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
    int recur(TreeNode* root) {
        if (root == NULL) return 0;
        int left = recur(root->left);
        if (left == -1) return -1;
        int right = recur(root->right);
        if (right == -1) return -1;
        // 从某个最底层节点开始，获取深度
        if (abs(right -  left) <= 1)
            return max(left, right) + 1;
        else
            return -1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return recur(root) != -1;
    }
};
