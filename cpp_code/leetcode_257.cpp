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
                // 在叶子节点添加路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        preOrder(root);
        for (int i = 0; i < nums.size(); i++) {
            string str;
            for (int j = 0; j < nums[i].size(); j++) {
                if (j != nums[i].size() - 1) 
                    str = str + to_string(nums[i][j]) + "->";
                else 
                    str = str + to_string(nums[i][j]);
            }
            result.push_back(str);
        }
        return result;
    }
};
