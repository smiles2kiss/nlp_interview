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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nums;
        if (root == NULL)
            return nums;

        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false) {
            vector<int> num;
            vector<TreeNode*> temp;

            while (q.empty() == false) {
                TreeNode* front = q.front();
                num.push_back(front->val);
                q.pop();

                if (front->left != NULL)
                    temp.push_back(front->left);
                if (front->right != NULL)
                    temp.push_back(front->right);
            }
            for (int i = 0; i < temp.size(); i++) {
                q.push(temp[i]);
            }
            nums.push_back(num);
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            vector<int> temp = nums[i];
            nums[i] = nums[nums.size() - 1 - i];
            nums[nums.size() - 1 - i] = temp;
        }
        return nums;
    }
};
