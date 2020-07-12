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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> left;
        if (root != NULL) {
            left = inorderTraversal(root->left);
            left.push_back(root->val);
            vector<int> right;
            right = inorderTraversal(root->right);
            for (int i = 0; i < right.size(); i++) {
                left.push_back(right[i]);
            }
        }
        return left;   
    }
};
