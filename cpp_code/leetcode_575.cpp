class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        // 保证获得的糖果的种类数最多
        unordered_map<int, int> map;
        for (auto candy: candies) map[candy]++;
        return min(map.size(), (candies.size() + 1) / 2);
    }
};
