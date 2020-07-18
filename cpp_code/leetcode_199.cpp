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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        int count = q.size();
        while(!q.empty()) {
            result.push_back(q.back()->val);
            while(count > 0) {
                TreeNode* node = q.front();
                q.pop();
                count = count - 1;
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            count = q.size();
        }
        return result;
    }
};
