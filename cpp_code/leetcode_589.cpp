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
    vector<int> results;
    void dfs(Node* root) {
        if (!root) return;
        results.push_back(root->val);
        vector<Node*> children = root->children;
        for (auto child:children) dfs(child);
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return results;
    }
};
