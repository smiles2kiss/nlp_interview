class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            if (target == 0) return 1;
            else return 0;
        }
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // 所有元素都不选
        for (int i = 1; i <= target; i++) {
            for (auto num: nums) {
                if (i >= num)
                    dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};
