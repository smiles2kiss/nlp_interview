class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash_table;
        for (auto num: nums1) hash_table[num]++;
        vector<int> result;
        for (auto num: nums2) {
            if (hash_table[num] > 0 && find(result.begin(), result.end(), num) == result.end())
                result.push_back(num);
        }
        return result;
    }
};
