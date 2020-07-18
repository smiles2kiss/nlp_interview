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
    int successor(TreeNode* node) {
        // �����������һ���ڵ�
        node = node->right;
        while (node && node->left != NULL)
            node = node->left;
        return node->val;
    }
    int predecessor(TreeNode* node) {
        // ���������ǰһ���ڵ�
        node = node->left;
        while (node && node->right != NULL)
            node = node->right;
        return node->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // �߽����ڵ��ɾ��
        // ����Ҫɾ���Ľڵ㽻����Ҷ�ӽڵ���
        if (root == NULL)
            return NULL;
        
        if (key > root->val) 
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else {
            if (root->left == NULL && root->right == NULL)
                root = NULL;
            else if (root->right != NULL) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};
