class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp;
        int len1 = A.size();
        int len2 = B.size();
        for (int i = 0; i <= len1; i++) {
            vector<int> temp(len2 + 1, 0);
            dp.push_back(temp);
        }

        // dp[i][j] ����A����iΪ����B����jΪ�����ظ�������ĳ���
        int max_len = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > max_len)
                    max_len = dp[i][j];
            }
        }
        return max_len;
    }
};
