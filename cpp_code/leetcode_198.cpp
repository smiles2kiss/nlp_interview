class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        
        vector<int> dp(len + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= len; i++) {
            if (nums[i-1] + dp[i - 2] > dp[i-1])
                dp[i] = nums[i-1] + dp[i-2];
            else 
                dp[i] = dp[i-1];
        }
        return dp[len];
    }
};
