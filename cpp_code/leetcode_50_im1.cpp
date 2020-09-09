class Solution {
public:
    double binpow(double a, int b) {
        if (b == 0) return 1;
        double res = binpow(a, b / 2);
        if (b % 2) return res * res * a;
        else return res * res;
    }

    double myPow(double x, long n) {
        if (x == 1) return 1;
        if (n < -INT_MAX - 1 || n > INT_MAX) return 0;
        else if (n == 0) return 1;
        else if (n  > 0) return binpow(x, n);
        else return binpow(1.0 / x, -n);
    }
};
