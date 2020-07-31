class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto num:nums) {
            map[num]++;
            if (map[num] > 1) return true;
        }
        return false;
    }
};
