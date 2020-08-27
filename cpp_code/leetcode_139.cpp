class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto word:wordDict) wordSet.insert(word);

        // dp[i] ��ʾ�ַ��� ss ǰ ii ���ַ���ɵ��ַ���
        // s[0..i-1]s[0..i?1] �Ƿ��ܱ��ո��ֳ����ɸ��ֵ��г��ֵĵ��ʡ�
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            // j�����
            for (int j = 0; j < i; j++) {
                // �ַ�����ǰi���ַ��ܹ��ָ�
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
