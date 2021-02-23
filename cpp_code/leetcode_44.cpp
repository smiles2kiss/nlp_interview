class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int len1 = s.length();
        int len2 = p.length();
        vector<bool> temp(len2+1, false);
        vector<vector<bool>> dp(len1+1, temp);
        dp[0][0] = true;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                // dp[i-1][j-1]: s = "ab",  p = "ab*"  // 匹配零个
                // dp[i][j-1]:   s = "abc", p = "ab*"  // 匹配一个
                // dp[i-1][j]:   s = "abc", p = "a*"   // 匹配多个
                if (p[j-1] == '*') 
                    dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                else if (p[j-1] == '?') 
                    dp[i][j] = dp[i-1][j-1];
                else if (s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[len1][len2];
    }
};
