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
    TreeNode* result = NULL;
    bool hasValue(TreeNode* root, TreeNode* node) {
        if (root != NULL) {
            if (root == node)
                return true;
            return hasValue(root->left, node) || hasValue(root->right, node);
        } else {
            return false;
        }
    } 
    void commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root != NULL) {
            if (hasValue(root, p) && hasValue(root, q)) 
                result = root;
            commonAncestor(root->left, p, q);
            commonAncestor(root->right, p, q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // ½áÊøÌõ¼þ
        commonAncestor(root, p, q);
        return result;
    }
};
