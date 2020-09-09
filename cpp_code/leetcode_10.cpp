class Solution {
public:
    bool isMatch(string s, string p) {
        // 动态规划思路
        // dp[i][j]代表s的前i个字符能否被p的前j个字符匹配
        s = " " + s;
        p = " " + p;
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    if (s[i-1] != p[j-2] && p[j-2] != '.') 
                        dp[i][j] = dp[i][j-2];
                    else 
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                }
            }
        }
        return dp[len1][len2];
    }
};
