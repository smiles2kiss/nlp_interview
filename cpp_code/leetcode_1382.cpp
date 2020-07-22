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
    // 递归构建二叉搜索树
    vector<int> path;
    void inOrder(TreeNode* root) {
        if (root != NULL) {
            inOrder(root->left);
            path.push_back(root->val);
            inOrder(root->right);
        }
    }
    // 二分查找构建二叉树
    TreeNode* construct(TreeNode* root, vector<int> &nums, int start, int end) {
        if (start <= end) {
            int mid = (start + end) / 2;
            root = new TreeNode(nums[mid]);
            root->left = construct(root->left, nums, start, mid - 1);
            root->right = construct(root->right, nums, mid + 1, end);
            return root;
        } else {
            return NULL;
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        TreeNode* result = NULL;
        result = construct(result, path, 0, path.size() - 1);
        return result;
    }
};
