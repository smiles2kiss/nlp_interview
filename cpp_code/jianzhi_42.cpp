class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len + 1, 0);
        int max_sum = nums[0];
        for (int i = 1; i <= len; i++) {
            if (dp[i-1]< 0) 
                dp[i] = nums[i-1];
            else 
                dp[i] = dp[i-1] + nums[i-1];
            if (dp[i] > max_sum)
                max_sum = dp[i];
        }
        return max_sum;
    }
};
