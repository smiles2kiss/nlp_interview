class Solution {
public:
    // ���Ƚڵ����Сֵ
    int min_val = 100001;
    // ���Ƚڵ����Сֵ
    int max_val = -1;
    // ��ǰ�ڵ�����Ƚڵ������ֵ
    int max_dif = -1;
    void dfs(TreeNode* root) {
        if (root) {
            // ���ڵ㲻�������
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
            // ������ǰ�ڵ��ֵ
            min_val = temp_min;
            max_val = temp_max;
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return max_dif;
    }
};
