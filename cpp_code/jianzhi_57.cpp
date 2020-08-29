class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> hash_set;
        for (auto num: nums) {
            if (hash_set.find(target - num) != hash_set.end()) {
                return vector<int> {num, target-num};
            }
            hash_set.insert(num);
        }
        return vector<int>{};
    }
};
