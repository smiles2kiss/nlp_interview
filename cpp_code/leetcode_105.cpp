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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> preorder, int pre_start, int pre_end, vector<int> inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end)
            return NULL;
        int val = preorder[pre_start];
        TreeNode* root = new TreeNode(val);
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == val) {
                int left_len = i - in_start;
                root->left = build(preorder, pre_start + 1, pre_start + left_len, inorder, in_start, i - 1);
                root->right = build(preorder, pre_start + left_len + 1, pre_end, inorder, i + 1, in_end);
            }
        }
        return root;
    }
};
