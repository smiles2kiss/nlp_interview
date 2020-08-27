class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 障碍物处不可达，将种类设置为0
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 存储到某个节点可能存在的路径数
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            dp.push_back(temp);
        }
        dp[0][0] = 1;
        if (obstacleGrid[0][0] == 1) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else {
                    if (i >= 1 && j >= 1)
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    else if (i >= 1)
                        dp[i][j] = dp[i-1][j];
                    else if (j >= 1)
                        dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
