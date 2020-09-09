class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        unordered_map<int, int> hash_set;
        for (auto num:nums) hash_set[num]++;
        for (auto item:hash_set) {
            if (item.second == 1) res.push_back(item.first);
        }
        return res;
    }
};
