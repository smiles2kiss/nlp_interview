class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return false;
        
        int sum = 0;
        for (auto num: nums) sum = sum + num;
        if (sum % 2 == 1) return false;

        int target = sum / 2;
        vector<vector<int>> dp(len+1, vector<int>(target+1, 0));

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i-1]) 
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]] + nums[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[len][target] == target ? true : false;
    }
};
