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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        if (root != NULL) {
            vector<int> left = postorderTraversal(root->left);
            vector<int> right = postorderTraversal(root->right);
            for (int i = 0; i < left.size(); i++) {
                nums.push_back(left[i]);
            }
            for (int i = 0; i < right.size(); i++) {
                nums.push_back(right[i]);
            }
            nums.push_back(root->val);
        }
        return nums;
    }
};
