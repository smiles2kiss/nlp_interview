class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto word:wordDict) wordSet.insert(word);

        // dp[i] 表示字符串 ss 前 ii 个字符组成的字符串
        // s[0..i-1]s[0..i?1] 是否能被空格拆分成若干个字典中出现的单词。
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            // j是起点
            for (int j = 0; j < i; j++) {
                // 字符串的前i个字符能够分割
                // s.substr(j, i-j) = s.substr(start, len)
                if (dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
