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
    vector<vector<int>> results;
    vector<int> temp;
    void preOrder(TreeNode* root) {
        if (!root) return;
        temp.push_back(root->val);
        if (!root->left && !root->right) 
            results.push_back(temp);
        preOrder(root->left);
        preOrder(root->right);
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> outputs;
        if (!root) return outputs;
        preOrder(root);
        for (auto result:results) {
            string output = "";
            for (int t = 0; t < result.size(); t++) {
                int num = result[t];
                if (t == 0) output += to_string(num);
                else output += "->" + to_string(num);
            }
            outputs.push_back(output);
        }
        return outputs;
    }
};
