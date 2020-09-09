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
class Solution {
public:
    bool isSame(TreeNode* a, TreeNode* b) {
        // 判断两个树是否完全相同
        if (!a && !b) return true;
        if (a && !b) return false;
        if (!a && b) return false;
        else return (a->val == b->val) && isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool preOrder(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isSame(s, t)) return true;
        else {
            bool left = preOrder(s->left, t);
            bool right = preOrder(s->right, t);
            return left || right;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return preOrder(s, t);
    }
};
