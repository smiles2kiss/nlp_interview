class Solution {
public:
    // 祖先节点的最小值
    int min_val = 100001;
    // 祖先节点的最小值
    int max_val = -1;
    // 当前节点和祖先节点的最大差值
    int max_dif = -1;
    void dfs(TreeNode* root) {
        if (root) {
            // 根节点不参与计算
            if (max_val != -1 && min_val != 100001) {
                if (abs(root->val - max_val) > max_dif)
                    max_dif = abs(root->val - max_val);
                if (abs(root->val - min_val) > max_dif)
                    max_dif = abs(root->val - min_val);
            }
            int temp_min = min_val;
            int temp_max = max_val;
            min_val = min(min_val, root->val);
            max_val = max(max_val, root->val);
            dfs(root->left);
            dfs(root->right);
            // 弹出当前节点的值
            min_val = temp_min;
            max_val = temp_max;
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return max_dif;
    }
};
