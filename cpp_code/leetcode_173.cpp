/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    queue<int> q;
    void preOrder(TreeNode* root) {
        if (root != NULL) {
            preOrder(root->left);
            q.push(root->val);
            preOrder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        preOrder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int num = q.front();
        q.pop();
        return num;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (q.empty())
            return false;
        else
            return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
