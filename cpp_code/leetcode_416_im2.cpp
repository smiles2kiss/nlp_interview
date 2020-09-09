class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 背包容量为sum/2，能否找到一个背包，使得价值和为sum/2
        int len = nums.size();
        if (len == 0) return false;

        int sum = 0;
        for (auto num:nums) sum += num;
        if (sum % 2 == 1) return false;

        int target = sum / 2;
        vector<vector<int>> dp(len, vector<int>(target+1, 0));
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i-1][j];

                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }

                if (nums[i] < j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[len-1][target];
    }
};
