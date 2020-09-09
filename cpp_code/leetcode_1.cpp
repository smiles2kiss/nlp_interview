class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (!hash_table.empty() && hash_table.find(target-num) != hash_table.end()) {
                int j = hash_table[target-num];
                res.push_back(min(i,j));
                res.push_back(max(i,j));
            }
            hash_table[num] = i;
        }
        return res;
    }
};
