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
    int maxDepth(Node* root) {
        if (!root) return 0;
        vector<Node*> children = root->children; 
        int mmax = 0;
        for (auto child:children) mmax = max(mmax, maxDepth(child));
        return mmax + 1;
    }
};
