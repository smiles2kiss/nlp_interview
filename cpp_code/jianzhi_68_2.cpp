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
        // 作为边界条件
        if (root == NULL)
            return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) // 左子树中一个节点也没找到，全在右子树中
            return right;
        if (right == NULL) // 左子树中一个节点也没找到，全在左子树中
            return left;
        if (left && right) // 由于取值唯一，p, q分别分布在左右子树中
            return root;
        return NULL;
    }
};
