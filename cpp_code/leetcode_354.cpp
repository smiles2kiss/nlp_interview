class Solution {
public:
    // 排序 + 最长递增子序列问题
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0]  && a[1] < b[1]);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp(len, 0);
        int res = 0;
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
