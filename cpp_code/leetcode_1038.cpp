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
    vector<int> path;
    int index = 0;
    void inOrder(TreeNode* root) {
        if (root != NULL) {
            inOrder(root->left);
            path.push_back(root->val);
            inOrder(root->right);
        }
    }
    void reConstruct(TreeNode* root, vector<int> nums) {
        if (root != NULL) {
            reConstruct(root->left, nums);
            root->val = nums[index];
            index++;
            reConstruct(root->right, nums);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        inOrder(root);
        int len = path.size();
        for (int i = len - 1 - 1; i >= 0; i--) 
            path[i] = path[i] + path[i+1];
        reConstruct(root, path);
        return root;
    }
};
