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
    int getDepth_complete(TreeNode* root) {
        int depth = 0;
        while (root) {
            depth = depth + 1;
            root = root->left;
        }
        return depth;
    }
    int getDepth(TreeNode* root) {
        if (root != NULL) 
            return max(getDepth(root->left), getDepth(root->right)) + 1;
        else
            return 0;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) 
            return 0;
        
        int left_depth = getDepth_complete(root->left);
        int right_depth = getDepth_complete(root->right);

        if (left_depth == right_depth) {
            // ����������������������������
            // �������ڵ���ĿΪpow(2, left_depth) - 1�����ڵ���ĿΪ1
            return pow(2, left_depth) + countNodes(root->right);
        } else {
            // ����������������������������
            return pow(2, right_depth) + countNodes(root->left);
        }
    }
};
