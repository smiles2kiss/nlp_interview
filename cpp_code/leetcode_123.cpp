class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        // dp[i][j] 表示在i位置处，股票状态为j的情况下，用户持有的收益
        // j = 0: 未交易    dp[i][0] = dp[i-1][0]
        // j = 1: 买入一次  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        // j = 2: 卖出一次  dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
        // j = 3: 买入两次  dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
        // j = 4: 卖出两次  dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
        
        vector<vector<int>> dp;
        for (int i = 0; i < n; i++) {
            vector<int> temp(5, 0);
            dp.push_back(temp);
        }
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < n; i++) {
            // 当前位置以及之前没有股票交易
            dp[i][0] = dp[i-1][0];
            // i之前买入一次 || i位置买入一次
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            // i之前卖出一次 || i位置卖出一次
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            // i之前买入两次 || i位置买入两次
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            // i之前卖出两次 || i位置卖出两次
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        // 最后卖一次获利多还是卖两次获利多
        return max(dp[n-1][2], dp[n-1][4]);
    }
};
