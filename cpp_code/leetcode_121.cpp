class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int min = prices[0];
        int max_reward = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > min) {
                max_reward = max(max_reward, prices[i] - min);
            }
            if (prices[i] < min) {
                min = prices[i];
            }
        }
        return max_reward;
    }
};
