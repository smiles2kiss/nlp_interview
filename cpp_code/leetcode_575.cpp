class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        // ��֤��õ��ǹ������������
        unordered_map<int, int> map;
        for (auto candy: candies) map[candy]++;
        return min(map.size(), (candies.size() + 1) / 2);
    }
};
