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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 后序遍历
        // root->val < 1: 需要从父节点处获得need个硬币
        // root->val > 1: 可以给父节点提供need个硬币
        // root->val = 1: 不变
        int need = 1 - root->val;
        ans += abs(left) + abs(right);
        return left + right + need;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
