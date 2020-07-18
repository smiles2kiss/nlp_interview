/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// �����������������򵱽��������ӵ�������ʱ��ԭʼ����������ʧ 
class Solution {
public:
    // ����ͷ�ڵ�
    TreeNode* pre = nullptr;
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};
