class Solution {
public:
    int Min(int a, int b, int c) {
        return min(min(a, b), c);
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;
        
        vector<vector<int>> dp;
        for (int i = 0; i <= len1; i++) {
            vector<int> temp(len2 + 1, 0);
            dp.push_back(temp);
        }
        for (int i = 0; i <= len1; i++)
            dp[i][0] = i;
        for (int j = 0; j <= len2; j++)
            dp[0][j] = j;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = Min(
                        dp[i-1][j] + 1,    // Ìæ»»word2µÄ×Ö·ûword2[j-1]
                        dp[i][j-1] + 1,    // É¾³ýword2µÄ×Ö·ûword2[j-1]
                        dp[i-1][j-1] + 1); // Ìæ»»word1µÄ×Ö·ûword1[i-1] ºÍword2µÄ×Ö·ûword2[j-1]
            }
        }
        return dp[len1][len2];
    }
};
