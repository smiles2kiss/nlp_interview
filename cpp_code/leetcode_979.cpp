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
        // �������
        // root->val < 1: ��Ҫ�Ӹ��ڵ㴦���need��Ӳ��
        // root->val > 1: ���Ը����ڵ��ṩneed��Ӳ��
        // root->val = 1: ����
        int need = 1 - root->val;
        ans += abs(left) + abs(right);
        return left + right + need;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
