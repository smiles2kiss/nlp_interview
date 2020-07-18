/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void stackOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            while (count > 0) {
                Node* node = q.front();
                q.pop();
                count = count - 1;
                if (count >= 1)
                    node->next = q.front();
                else
                    node->next = NULL;

                if (node->left) 
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            count = q.size();
        }
        
    }
    Node* connect(Node* root) {
        if (root == NULL)   
            return root;
        stackOrder(root);
        return root;
    }
};
