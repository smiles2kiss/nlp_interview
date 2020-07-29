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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            cout << root->val << endl;
            return root;
        }
        if (root == q) {
            cout << root->val << endl;
            return root;
        }
        // ��Ϊ�߽�����
        if (root == NULL)
            return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) // ��������һ���ڵ�Ҳû�ҵ���ȫ����������
            return right;
        if (right == NULL) // ��������һ���ڵ�Ҳû�ҵ���ȫ����������
            return left;
        if (left && right) // ����ȡֵΨһ��p, q�ֱ�ֲ�������������
            return root;
        return NULL;
    }
};
