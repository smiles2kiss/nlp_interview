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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        if (root != NULL) {
            nums.push_back(root->val);
            vector<int> left;
            left = preorderTraversal(root->left);
            vector<int> right;
            right = preorderTraversal(root->right);
            for (int i = 0; i < left.size(); i++) {
                nums.push_back(left[i]);
            }
            for (int i = 0; i < right.size(); i++) {
                nums.push_back(right[i]);
            }
        }
        return nums;
    }
};
