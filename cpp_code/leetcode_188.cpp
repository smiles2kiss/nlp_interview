class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        if (k >= n) k = n;
        // dp[j] 表示在i位置处，股票状态为j的情况下，用户持有的收益
        // j = 0: 未交易    dp[i][0] = dp[i-1][0]
        // j = 1: 买入一次  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        // j = 2: 卖出一次  dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
        // j = 3: 买入两次  dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
        // j = 4: 卖出两次  dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
        
        vector<int> dp(2 * k + 1, 0);
        dp[0] = 0; // 未交易
        for (int i = 0; i < k; i++) {
            dp[2*i+1] = -prices[0];
            dp[2*i+2] = 0;
        }

        for (int i = 1; i < n; i++) {
            // 当前位置以及之前没有股票交易
            dp[0] = dp[0];
            for (int j = 0; j < k; j++) {
                // i之前买入j + 1 次 || i位置买入 j + 1 次
                dp[2*j + 1] = max(dp[2*j + 1], dp[2*j] - prices[i]);
                // i之前卖出j + 1 次 || i位置卖出 j + 1 次
                dp[2*j + 2] = max(dp[2*j + 2], dp[2*j + 1] + prices[i]);
            }
        }
        int max_reward = 0;
        for (int i = 0; i < k; i++) max_reward = max(max_reward, dp[2*i + 2]);
        return max_reward;
    }
};
