class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // �������
        // dp[i][0]: ��ǰ���й�Ʊ
        // dp[i][1]: ��ǰδ���й�Ʊ
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][0] + prices[i] - fee, dp[i-1][1]);
        }
        return max(dp[len-1][0], dp[len-1][1]);
    }
};