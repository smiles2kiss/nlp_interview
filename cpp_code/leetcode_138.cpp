/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* temp = head;

        unordered_map<Node*, Node*> hash_table;
        hash_table[temp] = temp->random;

        Node* root = new Node(temp->val);
        Node* node = root;
        temp = temp->next;
        while (temp) {
            hash_table[temp] = temp->random;
            Node* cur = new Node(temp->val);
            node->next = cur;
            node = cur;
            temp = temp->next;
        }
        
        Node* node1 = head;
        Node* node2 = root;
        while (node1 && node2) {
            Node* temp1 = head;
            Node* temp2 = root;
            while (temp1 != hash_table[node1]) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            node2->random = temp2;
            
            node1 = node1->next;
            node2 = node2->next;
        }
        return root;
    }
};
