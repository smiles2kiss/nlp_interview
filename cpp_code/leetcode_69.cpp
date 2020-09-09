class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int ans = exp(0.5 * log(x));
        if ((long long)pow(ans + 1, 2) <= x) return ans + 1;
        else return ans;
    }
};
