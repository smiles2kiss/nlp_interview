class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        if (len < 2) return len;

        // dp[i][0]: [0, ..., i]区间内的湍流子数组的长度，并且nums[i] > nums[i-1]
        // dp[i][1]: [0, ..., i]区间内的湍流子数组的长度，并且nums[i] < nums[i-1]
        vector<vector<int>> dp(len, vector<int>({0, 0}));

        int ans = 1;
        dp[0][0] = 1;
        dp[0][1] = 1;
        if (A[1] > A[0]) {
            dp[1][0] = dp[0][1] + 1;
            dp[1][1] = 1;
        }
        else if (A[1] < A[0]) {
            dp[1][0] = 1;
            dp[1][1] = dp[0][0] + 1;
        }
        else {
            dp[1][0] = 1;
            dp[1][1] = 1;
        }
        ans = max(ans, max(dp[1][0], dp[1][1]));
        cout << ans << endl;

        for (int i = 2; i < len; i++) {
            if (A[i] > A[i-1]) {
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = 1;
            }
            else if (A[i] < A[i-1]) {
                dp[i][0] = 1;
                dp[i][1] = dp[i-1][0] + 1;
            }
            else {
                dp[i][0] = 1;
                dp[i][0] = 1;
            }

            ans = max(ans, max(dp[i][0], dp[i][1]));
            cout << ans << endl;
        }
        return ans;
    }
};
