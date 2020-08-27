class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        // dp[i][j] ��ʾ��iλ�ô�����Ʊ״̬Ϊj������£��û����е�����
        // j = 0: δ����    dp[i][0] = dp[i-1][0]
        // j = 1: ����һ��  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        // j = 2: ����һ��  dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
        // j = 3: ��������  dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
        // j = 4: ��������  dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
        
        vector<int> dp(5, 0);
        dp[0] = 0;
        dp[1] = -prices[0];
        dp[2] = 0;
        dp[3] = -prices[0];
        dp[4] = 0;

        for (int i = 1; i < n; i++) {
            // ��ǰλ���Լ�֮ǰû�й�Ʊ����
            dp[0] = dp[0];
            // i֮ǰ����һ�� || iλ������һ��
            dp[1] = max(dp[1], dp[0] - prices[i]);
            // i֮ǰ����һ�� || iλ������һ��
            dp[2] = max(dp[2], dp[1] + prices[i]);
            // i֮ǰ�������� || iλ����������
            dp[3] = max(dp[3], dp[2] - prices[i]);
            // i֮ǰ�������� || iλ����������
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        // �����һ�λ����໹�������λ�����
        return max(dp[2], dp[4]);
    }
};
