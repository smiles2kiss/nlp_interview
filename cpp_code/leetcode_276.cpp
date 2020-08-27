class Solution {
public:
    int numWays(int n, int k) {
        if (k * n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return pow(k, n);

        int dp1 = k; // ��ǰ��ɫ��ǰһ����ɫ��ͬʱ�������
        int dp2 = k * (k - 1); // ��ǰ��ɫ��ǰһ����ɫ��ͬʱ�������
        for (int i = 3; i <= n; i++) {
            int dp3 = (dp1 + dp2) * (k - 1);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp1 + dp2;
    }
};
