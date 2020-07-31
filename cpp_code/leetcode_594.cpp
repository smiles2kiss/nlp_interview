class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> hash_map;
        for (auto num: nums) hash_map[num]++;
        for (auto item: hash_map) {
            int num = item.first;
            if (hash_map.find(num + 1) != hash_map.end())
                result = max(result, hash_map[num] + hash_map[num+1]);
        }
        return result;
    }
};
