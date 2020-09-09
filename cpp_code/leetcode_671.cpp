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
    unordered_set<int> hash_set;
    priority_queue<int, vector<int>, greater<int>> q; // Ð¡¸ù¶Ñ
    void preOrder(TreeNode* root) {
        if (!root) return;
        hash_set.insert(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        preOrder(root);
        if (hash_set.size() < 2) return -1;
        for (auto num:hash_set) q.push(num);
        q.pop();
        return q.top();
    }
};
