class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int count = 1; // Ĭ���Ѿ�ѡ�˵�һ���ǹ�
        int len = candies.size();
        for (int i = 0; i < len - 1 && count < (len + 1) / 2; i++) {
            if (candies[i] < candies[i+1])
                count++;
        }
        return count;
    }
};
