class Solution {
public:
    int candy(vector<int>& ratings) {
        // ���ȸ�ÿ�����Ӷ�Ԥ�ȷ���һ���ǹ�
        int n = ratings.size();
        vector<int> candies;
        for (int i = 0; i < n; i++) {
            candies.push_back(1);
        }
        bool flag = true;
        while(flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                // ÿһ�ζ����ָߵĶ������ֵ͵��ھӵõ����ǹ���
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
