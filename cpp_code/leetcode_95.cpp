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
    vector<TreeNode*> generator(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<TreeNode*> ret;
        for (int i = start; i <= end; i++) {
            auto left  = generator(start, i - 1);
            auto right = generator(i + 1, end);
            for (auto node1: left) {
                for (auto node2: right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = node1;
                    node->right = node2;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) 
            return {};
        return generator(1, n);
    }
};
