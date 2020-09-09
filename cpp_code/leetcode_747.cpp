class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mmax = -INT_MAX;
        unordered_map<int,int> hash_table;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            mmax = max(mmax, nums[i]);
            hash_table[nums[i]] = i;
        }
        for (int i = 0; i < len; i++) {
            if (mmax != nums[i] && mmax < 2*nums[i]) return -1;
        }
        return hash_table[mmax];
    }
};
