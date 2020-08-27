class Solution {
public:
    int numWays(int n, int k) {
        if (k * n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return pow(k, n);

        int dp1 = k; // 当前颜色与前一种颜色相同时的情况数
        int dp2 = k * (k - 1); // 当前颜色与前一种颜色不同时的情况数
        for (int i = 3; i <= n; i++) {
            int dp3 = (dp1 + dp2) * (k - 1);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp1 + dp2;
    }
};
