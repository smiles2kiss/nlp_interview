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
    void inOrder(TreeNode* root, vector<long> &ans) {
        if (root != NULL) {
            inOrder(root->left, ans);
            ans.push_back(root->val);
            inOrder(root->right, ans);
        }
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<long> ans1;
        vector<long> ans2;
        inOrder(root1, ans1);
        inOrder(root2, ans2);

        // Ωµ–Ú≈≈¡–
        sort(ans1.rbegin(), ans1.rend());
        // …˝–Ú≈≈¡–
        sort(ans2.begin(), ans2.end());

        int i = 0;
        int j = 0;
        while (i < ans1.size() && j < ans2.size()) {
            int sum = ans1[i] + ans2[j];
            if (sum == target)
                return true;
            else if (sum < target)
                j++;
            else
                i++;
        }
        return false;
    }
};
