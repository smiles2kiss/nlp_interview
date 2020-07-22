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
    pair<int, int> rob_internal(TreeNode* root) {
        if (root == NULL)
            return make_pair(0, 0);
        pair<int, int> left = rob_internal(root->left);
        pair<int, int> right = rob_internal(root->right);
        
        // 当前节点选择不偷时，返回左孩子能偷到的钱 + 右孩子能偷到的钱
        int result1 = max(left.first, left.second)+ max(right.first, right.second);
        // 当前节点选择偷时，返回左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
        int result2 = left.first+ right.first+ root->val;
        // result1: 不偷
        // result2: 偷
        return make_pair(result1, result2);
    }
    int rob(TreeNode* root) {
        pair<int, int> result = rob_internal(root);
        return max(result.first, result.second);
    }
};
