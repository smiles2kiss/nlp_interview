/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> results;
        if (root == NULL) return results;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            vector<int> result;
            while (count > 0) {
                Node* top = q.front(); q.pop();
                result.push_back(top->val);
                vector<Node*> children = top->children;
                for (auto node:children) {
                    q.push(node);
                }
                count = count - 1;
            }
            results.push_back(result);
        }
        return results;
    }
};
