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
    // 找到两个叶子节点
    priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>, 
                   less<pair<int, TreeNode*>> > heap;
    void dfs(TreeNode* root, int depth) {
        if (root) {
            if (!root->left && !root->right) heap.push(make_pair(depth, root));
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b) {
        if (!root || a == root || b == root) return root;
        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);
        if (!left) return right;
        if (!right) return left;
        if (left && right) return root;
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        if (heap.size() == 1) 
            return heap.top().second;
        
        TreeNode* a = heap.top().second; int depth1 = heap.top().first; heap.pop();
        queue<TreeNode*> q;
        q.push(a);
        while (!heap.empty()) {
            TreeNode* b = heap.top().second; int depth2 = heap.top().first; heap.pop();
            if (depth2 == depth1) q.push(b);
            else break;
        }
        
        int count = q.size();
        if (count == 1) return a;
        if (count == 2) return lca(root, a, q.back());
        while (count >= 2) {
            while (count >= 1) {
                TreeNode* top1 = q.front(); q.pop();
                TreeNode* top2 = q.front(); q.pop();
                q.push(lca(root, top1, top2));
                count = count - 2;
            }
            count = q.size();
        }
        return q.front();
    }
};
