class Solution {
public:
    int candy(vector<int>& ratings) {
        // 首先给每个孩子都预先分配一个糖果
        int n = ratings.size();
        vector<int> candies;
        for (int i = 0; i < n; i++) {
            candies.push_back(1);
        }
        bool flag = true;
        while(flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                // 每一次都评分高的都比评分低的邻居得到的糖果多
                if (i != n - 1 && ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                    candies[i] = candies[i+1] + 1;
                    flag = true;
                }
                if (i != 0 && ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]) {
                    candies[i] = candies[i-1] + 1;
                    flag = true;
                }
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + candies[i];
        return sum;
    }
};
