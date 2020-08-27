class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int div = 1000000007;
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = dp[i][j-1] + arr[j-1];
                if (dp[i][j] % 2 == 1) ans = ans + 1;
            }
        }
        return ans % div;
    }
};
