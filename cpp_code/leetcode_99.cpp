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
    TreeNode* pre_node = NULL;
    void inOrder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
        if (root != NULL) {
            inOrder(root->left, list, vals);
            list.push_back(root);
            vals.push_back(root->val);
            inOrder(root->right, list, vals);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> vals;
        inOrder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); i++) {
            list[i]->val = vals[i];
        }
    }
};
