class Solution {
public:
    // 当前节点和祖先节点的最大差值
    int result = 0;
    void dfs(TreeNode* root, int min_val, int max_val) {
        if (root) {
            int dif1 = abs(root->val - min_val);
            int dif2 = abs(root->val - max_val);
            result = max(result, max(dif1, dif2));
            min_val = min(min_val, root->val);
            max_val = max(max_val, root->val);
            dfs(root->left, min_val, max_val);
            dfs(root->right, min_val, max_val);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return result;
    }
};
