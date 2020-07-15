/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 利用层次遍历找到所有路径 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<TreeNode*> end_node;

        if (root == NULL)
            return paths;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> path;
        path.push_back(root->val);
        paths.push_back(path);
        end_node.push_back(root);

        while (q.empty() == false) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left != NULL && front->right == NULL) {
                for (int i = 0; i < end_node.size(); i++) {
                    if (front == end_node[i]) {
                        paths[i].push_back(front->left->val);
                        end_node[i] = front->left;
                    }
                }
                q.push(front->left);
            }
            else if (front->left == NULL && front->right != NULL) {
                for (int i = 0; i < end_node.size(); i++) {
                    if (front == end_node[i]) {
                        paths[i].push_back(front->right->val);
                        end_node[i] = front->right;
                    }
                }
                q.push(front->right);
            }
            else if (front->left != NULL && front->right != NULL) {
                // 需要添加path
                int idx;
                for (int i = 0; i < end_node.size(); i++) {
                    if (front == end_node[i]) {
                        // cout << front->val << "\t";
                        vector<int> temp_path = paths[i];
                        paths.insert(paths.begin() + i + 1, temp_path);
                        paths[i].push_back(front->left->val);
                        paths[i+1].push_back(front->right->val);
                        idx = i;
                    }
                }
                end_node[idx] = front->left;
                end_node.insert(end_node.begin() + idx + 1, front);
                end_node[idx + 1] = front->right;
                q.push(front->left);
                q.push(front->right);
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < paths.size(); i++) {
            int _sum = 0;
            for (int j = 0; j < paths[i].size(); j++) {
                _sum = _sum + paths[i][j];
            }
            if (_sum == sum) {
                result.push_back(paths[i]);
            }
        }
        return result;
    }
};
