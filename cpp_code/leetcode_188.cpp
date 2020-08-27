class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        if (k >= n) k = n;
        // dp[j] ��ʾ��iλ�ô�����Ʊ״̬Ϊj������£��û����е�����
        // j = 0: δ����    dp[i][0] = dp[i-1][0]
        // j = 1: ����һ��  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        // j = 2: ����һ��  dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
        // j = 3: ��������  dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
        // j = 4: ��������  dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
        
        vector<int> dp(2 * k + 1, 0);
        dp[0] = 0; // δ����
        for (int i = 0; i < k; i++) {
            dp[2*i+1] = -prices[0];
            dp[2*i+2] = 0;
        }

        for (int i = 1; i < n; i++) {
            // ��ǰλ���Լ�֮ǰû�й�Ʊ����
            dp[0] = dp[0];
            for (int j = 0; j < k; j++) {
                // i֮ǰ����j + 1 �� || iλ������ j + 1 ��
                dp[2*j + 1] = max(dp[2*j + 1], dp[2*j] - prices[i]);
                // i֮ǰ����j + 1 �� || iλ������ j + 1 ��
                dp[2*j + 2] = max(dp[2*j + 2], dp[2*j + 1] + prices[i]);
            }
        }
        int max_reward = 0;
        for (int i = 0; i < k; i++) max_reward = max(max_reward, dp[2*i + 2]);
        return max_reward;
    }
};
