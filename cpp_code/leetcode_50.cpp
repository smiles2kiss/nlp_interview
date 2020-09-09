class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        double y = 1.0 / x;
        if (n == 0) return result;
        else if (n > 0) {
            for (int i = 1; i <= n; i++) result = result * x;
            return result;
        } 
        else {
            for (int i = 1; i <= -n; i++) result = result * y;
            return result;
        }
    }
};
