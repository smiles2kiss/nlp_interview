class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        // dp[i][j]: [i, j]范围内的数组的和
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        int ans = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = i; j <= len; j++) {
                if (nums[j-1] == 1) 
                    dp[i][j] = dp[i][j-1] + 1;
                else
                    dp[i][j] = dp[i][j-1] - 1;
                if (dp[i][j] == 0)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
