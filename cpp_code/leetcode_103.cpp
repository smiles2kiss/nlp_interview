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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        if (root == NULL)
            return nums;

        int flag = 0;
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
            for (int i = 0; i < temp.size(); i++) 
                q.push(temp[i]);
            if (flag == 1) {
                for (int i = 0; i < num.size() / 2; i++) {
                    int data = num[i];
                    num[i] = num[num.size() - 1 - i];
                    num[num.size() - 1 - i] = data;
                }
                flag = 0;
            } else {
                flag = 1;
            }
            nums.push_back(num);
        }
        return nums;
    }
};
