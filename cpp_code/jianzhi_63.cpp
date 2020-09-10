class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int mmax = -1;
        int res = 0;
        for (int i = len-1; i >= 0; i--) {
            res = max(res, mmax - prices[i]);
            mmax = max(prices[i], mmax);
        }
        return res;
    }
};
