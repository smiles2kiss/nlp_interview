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
    vector<int> res;
    unordered_map<int,int> hash_table;
    priority_queue<pair<int,int>> q;
    void dfs(TreeNode* root) {
        if (!root) return;
        hash_table[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if (!root) return res;
        dfs(root);
        for (auto item:hash_table) q.push(make_pair(item.second, item.first));
        int mmax = q.top().first;
        while (!q.empty() && q.top().first == mmax) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};
