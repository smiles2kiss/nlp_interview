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
    vector<string> paths;
    void preOrder(TreeNode* root, string path, vector<string> &paths) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) // 为叶子节点
            paths.push_back(path);
        else { // 非叶子节点
            path += "->";
            preOrder(root->left,  path, paths);
            preOrder(root->right, path, paths);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> outputs;
        preOrder(root, "", outputs);
        return outputs;
    }
};
