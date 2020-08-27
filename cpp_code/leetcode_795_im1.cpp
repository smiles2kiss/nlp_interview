class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        // dp[i][j] ��iΪ���jΪ�յ�����������ֵ
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = max(A[j-1], dp[i][j-1]);
                if (dp[i][j] >= L && dp[i][j] <= R) result++;
            }
        }
        return result;
    }
};
