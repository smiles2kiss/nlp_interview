class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int ans = nums[0];
        for (int i = 1; i <= n; i++) {
            if (dp[i-1] < 0) 
                dp[i] = nums[i-1];
            else 
                dp[i] = dp[i-1] + nums[i-1];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
