class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 0)
            return 0;
        sort(stones.begin(), stones.end());
        while (stones.size() >= 2) {
            int len = stones.size();
            int big1 = stones[len-1];
            int big2 = stones[len-2];
            stones.pop_back();
            stones.pop_back();
            if (big1 != big2) {
                stones.push_back(big1-big2);
                sort(stones.begin(), stones.end());
            }
        }
        if (stones.size() == 1)
            return stones[0];
        else
            return 0;
    }
};
