/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;
    TreeNode* dfs(TreeNode* root) {
        if (root != NULL) {
            if (root->left == NULL && root->right == NULL) {
                path.push_back(root->val);
                return NULL;
            }
            root->left = dfs(root->left);
            root->right = dfs(root->right);
        }
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root == NULL)
            return results;
        while(root) {
            root = dfs(root);
            results.push_back(path);
            vector<int> _path;
            path = _path;
        }
        return results;
    }
};
