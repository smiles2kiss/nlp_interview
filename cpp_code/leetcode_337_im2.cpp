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
        
        // ��ǰ�ڵ�ѡ��͵ʱ������������͵����Ǯ + �Һ�����͵����Ǯ
        int result1 = max(left.first, left.second)+ max(right.first, right.second);
        // ��ǰ�ڵ�ѡ��͵ʱ����������ѡ���Լ���͵ʱ�ܵõ���Ǯ + �Һ���ѡ��͵ʱ�ܵõ���Ǯ + ��ǰ�ڵ��Ǯ��
        int result2 = left.first+ right.first+ root->val;
        // result1: ��͵
        // result2: ͵
        return make_pair(result1, result2);
    }
    int rob(TreeNode* root) {
        pair<int, int> result = rob_internal(root);
        return max(result.first, result.second);
    }
};
