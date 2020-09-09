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
    vector<double> averageOfLevels(TreeNode* root) {
        // ²ã´Î±éÀú
        vector<double> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            double sum = 0;
            for (int i = 0; i < count; i++) {
                TreeNode* top = q.front(); q.pop();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
                sum = sum + top->val;
            }
            result.push_back(sum / count);
        }
        return result;
    }
};
