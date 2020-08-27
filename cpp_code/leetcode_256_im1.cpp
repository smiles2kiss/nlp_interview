class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        vector<vector<int>> dp(len + 1, vector<int>(3, 0));
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = 1e9;
                for (int k = 0; k < 3; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i-1][j]);
                    }
                }
            }
        }
        return min(min(dp[len][0], dp[len][1]), dp[len][2]);
    }
};
