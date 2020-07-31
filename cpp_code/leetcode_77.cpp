class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp;
    void dfs(vector<int> &nums, vector<bool> &used, int index, int count) {
        int len = nums.size();
        if (count == 0) {
            results.push_back(temp);
            return;
        } 
        for (int i = index; i < len; i++) {
            if (used[i])
                continue;
            temp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, i, count - 1);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<bool> used;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            used.push_back(false);
        }
        dfs(nums,used, 0, k);
        return results;
    }
};
