class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = t.length();
        int len2 = s.length();
        // dp[i][j] 代表 T 前 i 字符串可以由 S j 字符串组成最多个数.
        vector<vector<long long>> dp(len1+1, vector<long long>(len2+1, 0));
        for (int i = 0; i <= len2; i++) dp[0][i] = 1;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (t[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[len1][len2];
    }
};
