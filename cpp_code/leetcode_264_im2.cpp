class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        // dp[i]=min(dp[p_2]*2,dp[p_3]*3,dp[p_5]*5)
        int p_2 = 0;
        int p_3 = 0;
        int p_5 = 0;
        dp.at(0) = 1;
        for (int i = 1; i < n; i++) {
            // at，找到指定所有的值
            // 每次只加最小值
            int cur_p2 = 2 * dp.at(p_2); 
            int cur_p3 = 3 * dp.at(p_3);
            int cur_p5 = 5 * dp.at(p_5);
            dp.at(i) = min(min(cur_p2, cur_p3), cur_p5);
            if (dp.at(i) == cur_p2) 
                p_2++;
            if (dp.at(i) == cur_p3)
                p_3++;
            if (dp.at(i) == cur_p5)
                p_5++;
        }
        return dp.at(n-1);
    }
};
