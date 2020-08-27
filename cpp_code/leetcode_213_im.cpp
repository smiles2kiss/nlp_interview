class Solution {
public:
    int func(vector<int> &nums) {
        int len = nums.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[len];
    }
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        vector<int> temp1; temp1.assign(nums.begin(), nums.end() - 1);
        vector<int> temp2; temp2.assign(nums.begin() + 1, nums.end());
        return max(func(temp1), func(temp2));
    }
};
