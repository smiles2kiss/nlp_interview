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
    void inOrder(TreeNode* root, vector<int> &ans) {
        if (root != NULL) {
            inOrder(root->left, ans);
            ans.push_back(root->val);
            inOrder(root->right, ans);
        }
    }
    bool binary_search(vector<int> nums, int start, int end, int target) {
        if (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target) 
                return binary_search(nums, start, mid - 1, target);
            else
                return binary_search(nums, mid + 1, end, target);
        }
        return false;
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> ans1;
        vector<int> ans2;
        inOrder(root1, ans1);
        inOrder(root2, ans2);

        sort(ans2.begin(), ans2.end());
        for (int i = 0; i < ans1.size(); i++) {
            int left = target - ans1[i];
            if (binary_search(ans2, 0, ans2.size()-1, left))
                return true;
        }
        return false;
    }
};
