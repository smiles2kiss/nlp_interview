class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; i++) {
            int mmax = 1;
            for (int j = 1; j < i; j++) 
                mmax = max(mmax, max(j * (i-j), j * dp[i-j]));
            dp[i] = mmax;
        }
        return dp[n];
    }
};
