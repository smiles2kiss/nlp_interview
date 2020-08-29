class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> ans(n+1);
        ans[0] = 1;

        int pa = 1, pb = 1, pc = 1;
        for (int i = 1; i <= n; i++) {
            int mmin = min(min(pa * a, pb * b), pc * c);
            if (mmin == pa * a) pa++;
            if (mmin == pb * b) pb++;
            if (mmin == pc * c) pc++;
            cout << mmin << endl;
            ans[i] = mmin;
        }
        return ans[n];
    }
};
