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
    // ²ã´Î±éÀú
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (!root->left && !root->right) 
            return root->val;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        int sum = root->val;
        while (!q.empty()) {
            sum = 0;
            while (count > 0) {
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                count = count - 1;
            }
            count = q.size();
        }
        return sum;
    }
};
