class Solution {
public:
    int candy(vector<int>& ratings) {
        // 首先给每个孩子都预先分配一个糖果
        int n = ratings.size();
        
        // 从左到右保证得分更高的孩子获得更多的糖果
        // 从右到左保证得分最高的孩子获得更多的糖果
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + candies[i];
        return sum;
    }
}; 
