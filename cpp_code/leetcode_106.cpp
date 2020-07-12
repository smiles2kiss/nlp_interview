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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* build(vector<int> inorder, int in_start, int in_end, vector<int> postorder, int post_start, int post_end) {
        if (in_start > in_end || post_start > post_end) 
            return NULL;
        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);

        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == root_val) {
                int left_len = i - in_start;
                root->left = build(inorder, in_start, i - 1, postorder, post_start, post_start + left_len - 1);
                root->right = build(inorder, i + 1, in_end, postorder, post_start + left_len, post_end - 1);
            }
        }
        return root;
    }
};
