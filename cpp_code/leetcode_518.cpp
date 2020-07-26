class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if (len == 0)
            if (amount == 0)
                return 1; // û��Ԫ��ʱ��ֻ������Ԫ�ض���ѡ
            else
                return 0;
        
        vector<vector<int>> dp;
        for (int i = 0; i <= len; i++) {
            vector<int> temp(amount + 1, 0);
            dp.push_back(temp);
        }

        // ���Ǳ߽�����
        for (int i = 0; i <= len; i++)
            dp[i][0] = 1;  // ������������Ϊ0ʱ��ֻ��һ��ѡ��������Ʒ����ѡ

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[len][amount];
    }
};
