class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans(n);
        ans[0] = 1;
        
        int k = primes.size();
        vector<int> kv(k, 0);
        for (int i = 1; i < n; i++) {
            int mmin = INT_MAX;
            for (int j = 0; j < k; j++) {
                mmin = min(mmin, ans[kv[j]] * primes[j]);
            }

            for (int j = 0; j < k; j++) {
                if (ans[kv[j]] * primes[j] == mmin) {
                    kv[j]++;
                }
            }
            ans[i] = mmin;
        }
        return ans[n-1];
    }
};
