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
    TreeNode* ancestor = nullptr;
    int max_depth = 0;
    int dfs(TreeNode* node, int depth) {
        if (!node) return depth - 1;
        int left_depth = dfs(node->left, depth+1);
        int right_depth = dfs(node->right, depth+1);
        max_depth = max(max_depth, max(left_depth, right_depth));
        // 左右子树都有最深叶子节点
        if (left_depth == max_depth && right_depth == max_depth) 
            ancestor = node;
        return max(left_depth, right_depth);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return ancestor;
    }
};
