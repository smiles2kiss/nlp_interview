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
    unordered_map<int, int> hash_table;
    void preOrder(TreeNode* root) {
        if (!root) return;
        preOrder(root->left);
        hash_table[root->val]++;
        preOrder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        preOrder(root);
        for (auto item:hash_table) {
            int num = item.first;
            if (hash_table.find(k - num) != hash_table.end()) {
                if (num != k - num) return true;
                else {
                    if (hash_table[num] >= 2) return true;
                }
            }
        }
        return false;
    }
};
