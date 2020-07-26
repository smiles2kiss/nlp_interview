class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if (len == 0)
            if (amount == 0)
                return 1; // 没有元素时，只有所有元素都不选
            else
                return 0;
        
        vector<vector<int>> dp;
        for (int i = 0; i <= len; i++) {
            vector<int> temp(amount + 1, 0);
            dp.push_back(temp);
        }

        // 考虑边界条件
        for (int i = 0; i <= len; i++)
            dp[i][0] = 1;  // 即当背包容量为0时，只有一种选择，所有物品都不选

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
