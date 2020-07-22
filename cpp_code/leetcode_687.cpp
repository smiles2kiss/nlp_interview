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
    int ans = 0;
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
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight); 
    }
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        arrowLength(root);
        return ans;
    }
}; 
