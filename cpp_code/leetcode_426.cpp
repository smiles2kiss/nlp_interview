/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = NULL;
    Node* last = NULL;
    void helper(Node* node) {
        if (node) {
            helper(node->left);
            // �����һ���ڵ�ƴ����ȥ
            if (first == NULL) {
                first = node; // first����������ĵ�һ���ڵ�
            }
            else {
                last->right = node;
                node->left = last;
            }
            last = node;
            helper(node->right);
        }
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        helper(root);
        first->left = last;
        last->right = first;
        return first;
    }
};
