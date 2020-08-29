class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        int ans;
        for (auto num:nums) hash_table[num]++;
        for (auto item:hash_table) {
            if (item.second == 1)  {
                ans = item.first;
                break;
            }
        }
        return ans;
    }
};
