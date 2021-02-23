class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash_table;
        for (auto num:nums) hash_table[num]++;
        for (auto item:hash_table) {
            if (item.second == 1) return item.first;
        }
        return 0;
    }
};
