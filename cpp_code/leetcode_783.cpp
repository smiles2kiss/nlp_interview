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
    int pre;
    bool flag = false;
    int min = 10000;
    void inOrder(TreeNode* root) {
        if (root != NULL) {
            inOrder(root->left);
            if (flag == false) {
                pre = root->val;
                flag = true;
            } else {
                if (abs(root->val - pre) < min)
                    min = abs(root->val - pre);
                pre = root->val;
            }
            inOrder(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return min;
    }
};
