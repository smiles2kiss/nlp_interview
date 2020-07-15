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
    vector<vector<int>> result;
    void dfs(TreeNode *root, vector<int> &path, int sum) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->val == sum && root->left == NULL && root->right == NULL)
            result.push_back(path);
        if (root->left)
            dfs(root->left, path, sum - root->val);
        if (root->right) 
            dfs(root->right, path, sum - root->val);
        // 为什么要弹出最后一个元素
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, path, sum);
        return result;
    }
};
