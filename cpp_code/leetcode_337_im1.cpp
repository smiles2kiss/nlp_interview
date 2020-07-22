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
    unordered_map<TreeNode*, int> hash_map;
    int rob_internal(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (hash_map.find(root) != hash_map.end())
            return hash_map[root];
        
        int money = root->val;
        if (root->left)
            money = money + rob_internal(root->left->left) + rob_internal(root->left->right);
        
        if (root->right)
            money = money + rob_internal(root->right->left) + rob_internal(root->right->right);
        
        int result = max(money, rob(root->left) + rob(root->right));
        hash_map[root] = result;
        return result;
    }
    int rob(TreeNode* root) {
        return rob_internal(root);
    }
};
