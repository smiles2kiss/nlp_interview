class Solution {
public:
    vector<int> inOrder(TreeNode *root) {
        vector<int> nums;
        if (root != NULL) {
            vector<int> left = inOrder(root->left);
            for (int i = 0; i < left.size(); i++) {
                nums.push_back(left[i]);
            }
            nums.push_back(root->val);
            vector<int> right = inOrder(root->right);
            for (int i = 0; i < right.size(); i++) {
                nums.push_back(right[i]);
            }
        }
        return nums;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        vector<int> inorder = inOrder(root);
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i] >= inorder[i + 1])
                return false;
        }
        return true;
    }
};
