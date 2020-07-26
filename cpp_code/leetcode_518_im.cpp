class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if (len == 0)
            if (amount == 0)
                return 1; // û��Ԫ��ʱ��ֻ������Ԫ�ض���ѡ
            else
                return 0;
        
        vector<int> dp(amount + 1, 0);
        // ���Ǳ߽�����: ������������Ϊ0ʱ��ֻ��һ��ѡ��������Ʒ����ѡ
        dp[0] = 1;

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i-1])
                    dp[j] = dp[j] + dp[j-coins[i-1]];
                else
                    dp[j] = dp[j];
            }
        }
        return dp[amount];
    }
};
