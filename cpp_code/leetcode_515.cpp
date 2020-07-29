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
    vector<int> largestValues(TreeNode* root) {
        vector<int> nums;
        if (root == NULL) return nums;

        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            int num = q.front()->val;
            while (count > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val > num)
                    num = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                count = count - 1;
            }
            nums.push_back(num);
            count = q.size();
        }
        return nums;
    }
};
