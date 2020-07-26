class Solution {
public:
    
    int dp(int K, int N) {
        if (K == 1) return N; // 顺序遍历 需要移动的次数
        if (K == 0) return 0;

        int result = 99999;
        for (int i = 1; i <= N; i++) {
            result = min(
                result,
                max(
                    dp(K-1, i-1), //在第i楼的时候碎了
                    dp(K, N - i)  //在第i楼的时候没碎
                ) + 1  // 已经做了一次尝试
            );
        }
        return result;
    }
    int superEggDrop(int K, int N) {
        // dp[i][j]: i 表示鸡蛋数，j表示楼层数, dp[i][j]表示最小移动次数
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
                    dp[i-1][j-1], // 鸡蛋碎了
                    dp[i][N-j]    // 鸡蛋碎了
                );
            }
        }
        return dp[K][N];
    }
};
