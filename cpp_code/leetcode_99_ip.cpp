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
    TreeNode* node1 = NULL;
    TreeNode* node2 = NULL;
    void inOrder(TreeNode *root) {
        if (root != NULL) {
            inOrder(root->left);
            if (pre_node != NULL && pre_node->val > root->val) {
                if (node1 == NULL) {
                    node1 = pre_node;
                    node2 = root;
                } else {
                    node2 = root;
                }
            }
            pre_node = root;
            inOrder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
