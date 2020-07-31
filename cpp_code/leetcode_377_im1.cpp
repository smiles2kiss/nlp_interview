class Solution {
public:
    unordered_map<int, int> hash_map;
    int dfs(vector<int> &nums, int target) {
        if (target < 0) return 0;
        if (target == 0) return 1;
        if (hash_map[target] != -1) return hash_map[target];
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; i++)
            res += dfs(nums, target-nums[i]);
        hash_map[target] = res;
        return res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= target; i++) hash_map[i] = -1;
        dfs(nums, target);
        return hash_map[target];
    }
};
