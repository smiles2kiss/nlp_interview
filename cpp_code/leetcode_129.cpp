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
    vector<vector<int>> nums;
    vector<int> s;
    void preOrder(TreeNode* root) {
        if (root != NULL) {
            s.push_back(root->val);
            if (root->left == NULL && root->right == NULL) {
                nums.push_back(s);
                s.pop_back();
            } else {
                preOrder(root->left);
                preOrder(root->right);
                s.pop_back();
            }
        } else {
        }
    }
    int sumNumbers(TreeNode* root) {
        preOrder(root);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = 0;
            for (int j = 0; j < nums[i].size(); j++) {
                num = num * 10 + nums[i][j];
            }
            sum = sum + num;
        }
        return sum;
    }
};
