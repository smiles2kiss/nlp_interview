class Solution {
public: 
    vector<int> nodes;
    
    // DFS���ڼ�¼�������У����нڵ�ĸ��ڵ�
    unordered_map<TreeNode*, TreeNode*> hash_map; // ��ϣ��
    void dfs(TreeNode* root, TreeNode* pre) {
        if (root) {
            hash_map[root] = pre;
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }

    // BFS����target�ڵ�������ֱ����ڵ㡢�ҽڵ㡢���ڵ㷽���������֤���ظ�
	��������ĳ���ڵ���������������нڵ�ľ���
    vector<int> bfs(TreeNode* root, TreeNode* target, int K) {
        queue<TreeNode*> nodes;
        unordered_set<TreeNode*> visited;

        nodes.push(target);
        visited.insert(target);

        vector<int> result;
        while (!nodes.empty()) {
            if (K == 0) { // �պ�����K��
                while (!nodes.empty()) {
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    result.push_back(node->val);
                }
                return result;
            } else {
                // ��ǰ���������нڵ���������1���ڵ�
                int num = nodes.size();
                for (int i = 0; i < num; i++) {
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    // ������������
                    if (node->left && visited.find(node->left) == visited.end()) {
                        nodes.push(node->left);
                        visited.insert(node->left);
                    }
                    // ������������
                    if (node->right && visited.find(node->right) == visited.end()) {
                        nodes.push(node->right);
                        visited.insert(node->right);
                    }
                    // �򸸽ڵ�����
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
