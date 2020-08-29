class Solution {
public:
    // 求a, b的最大公倍数
    long LCM(long a, long b) {
        return a * (b / __gcd(a, b));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long ab = LCM(a, b);
        long ac = LCM(a, c);
        long bc = LCM(b, c);
        long abc = LCM(ab, c);

        long l = min(a, min(b, c));
        long r = 2 * 10e9;
        while (l < r) {
            long m = l + (r - l) / 2;
            long count = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
            if (count < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
