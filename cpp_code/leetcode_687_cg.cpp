/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 考虑必须要经过根节点的情况 
class Solution {
public:
    int arrowLength(TreeNode* root) {
        if (root == NULL)   return 0;
        int left = arrowLength(root->left);
        int right = arrowLength(root->right);
        int arrowLeft = 0;
        int arrowRight = 0;
        if (root->left && root->val == root->left->val) 
            arrowLeft += left + 1;
        if (root->right && root->val == root->right->val)
            arrowRight += right + 1;
        return max(arrowLeft, arrowRight); 
    }
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        return arrowLength(root);
    }
}; 
