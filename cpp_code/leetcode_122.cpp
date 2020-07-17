class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ��ȷ�
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];

        int max_profit = 0;
        int max_pos = prices.size() - 1;
        while(i < max_pos) {
            // �ҵ���һ������
            while (i < max_pos && prices[i] >= prices[i+1]) {
                i++;
            }
            valley = prices[i];
            // �ҵ���һ������
            while (i < max_pos && prices[i] <= prices[i+1]) {
                i++;
            }
            peak = prices[i];
            max_profit = max_profit + peak - valley;
        }
        return max_profit;
    }
};
