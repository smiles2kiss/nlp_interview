class Solution {
public:
    
    int dp(int K, int N) {
        if (K == 1) return N; // ˳����� ��Ҫ�ƶ��Ĵ���
        if (K == 0) return 0;

        int result = 99999;
        for (int i = 1; i <= N; i++) {
            result = min(
                result,
                max(
                    dp(K-1, i-1), //�ڵ�i¥��ʱ������
                    dp(K, N - i)  //�ڵ�i¥��ʱ��û��
                ) + 1  // �Ѿ�����һ�γ���
            );
        }
        return result;
    }
    int superEggDrop(int K, int N) {
        // dp[i][j]: i ��ʾ��������j��ʾ¥����, dp[i][j]��ʾ��С�ƶ�����
        if (K == 0)
            return 0;
        if (K == 1)
            return N;
        vector<vector<int>> dp;
        for (int i = 0; i <= K; i++) {
            vector<int> temp(N + 1, 0);
            dp.push_back(temp);
        }
        for (int i = 0; i <= N; i++) {
            dp[0][i] = 0;
            dp[1][i] = i;
        }

        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = min (
                    dp[i-1][j-1], // ��������
                    dp[i][N-j]    // ��������
                );
            }
        }
        return dp[K][N];
    }
};
