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
    // 定义头节点
    TreeNode* last = new TreeNode(0);
    void preOrder(TreeNode* root) {
        if (root != NULL) {
            TreeNode* temp = new TreeNode(root->val);
            last->right = temp;
            last = temp;
            cout << root->val << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void flatten(TreeNode* root) {
        preOrder(root);
        root = last->right;
    }
};
