class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;
    vector<bool> used;
    void dfs(int depth, vector<int> &nums) {
        int len = nums.size();
        if (depth == len) {
            results.push_back(path);
            return;
        } 
        for (int i = 0; i < len; i++) {
            if (used[i]) // 已经访问过
                continue;
            if (i > 0 && !used[i-1] && nums[i] == nums[i - 1]) // 已经访问过
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(depth + 1, nums);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return results;
        sort(nums.begin(), nums.end());
        vector<bool> _used(len, false);
        used = _used;
        dfs(0, nums);
        return results;
    }
};
