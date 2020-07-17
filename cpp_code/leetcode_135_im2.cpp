class Solution {
public:
    int candy(vector<int>& ratings) {
        // ���ȸ�ÿ�����Ӷ�Ԥ�ȷ���һ���ǹ�
        int n = ratings.size();
        
        // �����ұ�֤�÷ָ��ߵĺ��ӻ�ø�����ǹ�
        // ���ҵ���֤�÷���ߵĺ��ӻ�ø�����ǹ�
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
