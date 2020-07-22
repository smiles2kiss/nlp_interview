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
    bool binary_search(vector<long> nums, int start, int end, int target) {
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
        vector<long> ans1;
        vector<long> ans2;
        inOrder(root1, ans1);
        inOrder(root2, ans2);

        // // Ωµ–Ú≈≈¡–
        // sort(ans1.rbegin(), ans2.rend());
        // …˝–Ú≈≈¡–
        sort(ans2.begin(), ans2.end());

        for (int i = 0; i < ans1.size(); i++) {
            int left = target - ans1[i];
            // if (binary_search(ans2, 0, ans2.size()-1, left))
            //     return true;
            int start = 0;
            int end = ans2.size() - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (ans2[mid] == left)
                    return true;
                else if (ans2[mid] > left) 
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
};
