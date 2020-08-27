class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int _min = 99999;
        int _max = 0;
        int max_reward = 0;
        int i = 0; // 0表示当前数比前一个数小，1表示当前数比前一个数大
        while (i < n){
            // 找到波谷
            while (i < n && prices[i] <= _min) {
                _min = prices[i];
                i = i + 1;
            }
            if (i >= n) break;

            // 找到波峰
            _max = _min;
            while (i < n && prices[i] >= _max) {
                _max = prices[i];
                i = i + 1;
            }
            max_reward += _max - _min;
            if (i < n) {
                _max = prices[i-1];
                _min = prices[i-1];
            }
        }
        return max_reward;
    }
};
