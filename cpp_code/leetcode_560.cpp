class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] == k ? 1 : 0;

        // dp[i][j] 以i为起点j为终点的子数组和
        vector<vector<int>> dp;
        for (int i = 0; i < n + 1; i++) {
            vector<int> temp(n + 1, 0);
            dp.push_back(temp);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = dp[i][j-1] + nums[j - 1];
                if (dp[i][j] == k) ans = ans + 1;
            }
        }
        return ans;
    }
};
