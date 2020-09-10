class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 3�����
        // dp[i][0]: ���й�Ʊ
        // dp[i][1]: δ���й�Ʊ�������䶳��
        // dp[i][2]: δ���й�Ʊ��δ�����䶳��
        int len = prices.size();
        if (len == 0) return 0;

        vector<vector<int>> dp(len, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]); // ��һ�ֳ��й�Ʊ����ǰ�����Ʊ
            dp[i][1] = dp[i-1][0] + prices[i]; // ��������Ʊ
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]); // ��һ��δ���й�Ʊ����һ�δ����䶳�ڣ���һ�δ����䶳��
        }
        return max(dp[len-1][1], dp[len-1][2]);
    }
};
