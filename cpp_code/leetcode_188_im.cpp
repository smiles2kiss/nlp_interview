class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k == 0 || n < 2) return 0;
        if (k >= n / 2) {
            int max_reward = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1])
                    max_reward += prices[i] - prices[i-1];
            }
            return max_reward;
        }
        vector<int> dp(2*k, -99999);
        dp[0] = -prices[0]; // buy
        for (int i = 1; i < n; i++) {
            dp[0] = max(dp[0], -prices[i]); // first buy
            for (int j = 1; j < 2*k; j++) {
                if (j % 2) // j == 1
                    dp[j] = max(dp[j], dp[j-1] + prices[i]); // sell
                else       // j == 0
                    dp[j] = max(dp[j], dp[j-1] - prices[i]); // buy
            }
        }
        return max(0, dp.back());
    }
};
