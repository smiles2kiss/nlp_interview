class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        
        vector<vector<int>> dp;
        for (int i = 0; i <= len; i++) {
            vector<int> temp(len + 1, 0);
            dp.push_back(temp);
        }
        for (int i = 1; i <= len; i++) {
            dp[1][i] = nums[i];
            dp[i][1] = nums[i];
        }
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= len; j++) {
                int pos0 = (i + 1) % len;
                int pos1 = (i - 1+ 1) % len;
                int pos2 = (i - 2+ 1) % len;
                if (nums[pos1] + dp[i][pos2] > dp[i][pos1])
                    dp[i][pos0] = nums[pos1] + dp[i][pos2];
                else 
                    dp[i][pos0] = dp[i][pos1];
            }
        }
        return dp[len][len];
    }
};
