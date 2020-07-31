class Solution {
public:
    int count = 0;
    void dfs(vector<int> &nums, int target) {
        if (target < 0) return;
        if (target == 0) {count++; return;}
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            dfs(nums, target-nums[i]);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        dfs(nums, target);
        return count;
    }
};
