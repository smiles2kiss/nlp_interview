class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 0) return 0;

        int n = triangle[m-1].size();
        if (n == 0) return 0;
        if (m == 1 && n == 1) return triangle[0][0];
        if (m == 1 && n > 1) {
            int mn = 100000;
            for (int i = 0; i < n; i++) mn = min(mn, triangle[0][i]);
            return mn;
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= triangle[i-1].size(); j++) {
                if (j == i) 
                    dp[i][j] = dp[i-1][j-1] + triangle[i-1][j-1];
                else if (j == 1)
                    dp[i][j] = dp[i-1][j] + triangle[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i-1][j-1];
            }
        }
        int ans = 100000;
        for (int j = 1; j <= n; j++) ans = min(ans, dp[m][j]);
        return ans;
    }
};
