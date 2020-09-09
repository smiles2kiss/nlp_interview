class Solution {
public:
    typedef long long LL;
    int getCnt(LL n, LL prefix){
        LL cnt = 0;
        for (LL first = prefix, second = prefix+1; first<=n; first*=10, second*=10){
            cnt+= min(n + 1, second) - first;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k--;
        while (k > 0) {
            int cnt = getCnt(n, prefix);
            if (cnt <= k) {
                k -= cnt;
                prefix++;
            } else {
                k--;
                prefix*=10;
            }
        }
        return prefix;
    }
};
