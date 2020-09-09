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
    int res = -INT_MAX;
    // 思路1: 不一定是两个节点之间
    // 思路2: 不一定需要到叶子节点
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left  = dfs(root->left);
        int right = dfs(root->right);
        if (left  < 0) left  = 0;
        if (right < 0) right = 0;
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }
};
