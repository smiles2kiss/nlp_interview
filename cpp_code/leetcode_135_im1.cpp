class Solution {
public:
    int candy(vector<int>& ratings) {
        // 首先给每个孩子都预先分配一个糖果
        int n = ratings.size();
        
        // 从左到右保证得分更高的孩子获得更多的糖果
        // 从右到左保证得分最高的孩子获得更多的糖果
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                left2right[i] = left2right[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i+1] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // 取最大值，则节点i既大于左邻居，也大于右邻居
            sum = sum + max(left2right[i], right2left[i]);
        }
        return sum;
    }
}; 
