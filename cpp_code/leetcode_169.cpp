class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> hash_table;
        for (auto num:nums) {
            hash_table[num]++;
            if (hash_table[num] > len/2) return num;
        }
        return 0;
    }
};
