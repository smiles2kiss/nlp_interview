class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2)
            return false;
        vector<vector<int>> dp;
        for (int i = 0; i <= len; i++) {
            vector<int> temp(len + 1, 0);
            dp.push_back(temp);
        }
        for (int i = 1; i <= len; i++) {
            for (int j = i; j <= len; j++) {
                dp[i][j] = dp[i][j-1] + nums[j-1];
                if (j - i > 0) {
                    if (k != 0 && dp[i][j] % k == 0)
                        return true;
                    if (k == 0 && dp[i][j] == 0)
                        return true;
                }
            }
        }
        return false;
    }
};
