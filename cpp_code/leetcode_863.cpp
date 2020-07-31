class Solution {
public: 
    vector<int> nodes;
    
    // DFS用于记录二叉树中，所有节点的父节点
    unordered_map<TreeNode*, TreeNode*> hash_map; // 哈希表
    void dfs(TreeNode* root, TreeNode* pre) {
        if (root) {
            hash_map[root] = pre;
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }

    // BFS，从target节点出发，分别从左节点、右节点、父节点方向遍历，保证不重复
	二叉树中某个节点与二叉树其他所有节点的距离
    vector<int> bfs(TreeNode* root, TreeNode* target, int K) {
        queue<TreeNode*> nodes;
        unordered_set<TreeNode*> visited;

        nodes.push(target);
        visited.insert(target);

        vector<int> result;
        while (!nodes.empty()) {
            if (K == 0) { // 刚好延伸K次
                while (!nodes.empty()) {
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    result.push_back(node->val);
                }
                return result;
            } else {
                // 当前队列中所有节点向外延伸1个节点
                int num = nodes.size();
                for (int i = 0; i < num; i++) {
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    // 向左子树延伸
                    if (node->left && visited.find(node->left) == visited.end()) {
                        nodes.push(node->left);
                        visited.insert(node->left);
                    }
                    // 向右子树延伸
                    if (node->right && visited.find(node->right) == visited.end()) {
                        nodes.push(node->right);
                        visited.insert(node->right);
                    }
                    // 向父节点延伸
                    if (hash_map[node] && visited.find(hash_map[node]) == visited.end()) {
                        nodes.push(hash_map[node]);
                        visited.insert(hash_map[node]);
                    }
                }
                K = K - 1;
            }
        }
        return result;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, NULL);
        return bfs(root, target, K);
    }
};
