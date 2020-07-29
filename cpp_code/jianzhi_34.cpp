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
    vector<vector<int>> results;
    vector<int> path;

    // DFS: �ȴ�����ڵ�
    void dfs(TreeNode* root, int sum) {
        if (root == NULL) return;
        path.push_back(root->val);
        sum = sum - root->val;

        // ��Ҷ�ӽڵ����·��
        if (sum == 0 && !root->left && !root->right) 
            results.push_back(path);
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return results;
    }
};
