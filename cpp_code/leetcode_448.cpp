class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (auto num:nums) hash_set.insert(num);
        vector<int> results;
        for (int i = 1; i <= nums.size(); i++) {
            if (hash_set.find(i) == hash_set.end()) 
                results.push_back(i);
        }
        return results;
    }
};
