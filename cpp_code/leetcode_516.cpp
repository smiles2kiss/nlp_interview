class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) return true;
        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) 
                return false;
        }
        return true;
    }
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        // dp 数组全部初始化为 0
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) dp[i][i] = 1;
        // 从右下角遍历到右上角
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2; 
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][len-1];
    }
};
