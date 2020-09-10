class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 3种情况
        // dp[i][0]: 持有股票
        // dp[i][1]: 未持有股票，处于冷冻期
        // dp[i][2]: 未持有股票，未处于冷冻期
        int len = prices.size();
        if (len == 0) return 0;

        vector<vector<int>> dp(len, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]); // 上一轮持有股票，当前购入股票
            dp[i][1] = dp[i-1][0] + prices[i]; // 刚卖出股票
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]); // 上一次未持有股票，上一次处于冷冻期，上一次处于冷冻期
        }
        return max(dp[len-1][1], dp[len-1][2]);
    }
};
