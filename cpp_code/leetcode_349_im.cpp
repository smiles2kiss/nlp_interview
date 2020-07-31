class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        for (auto num: nums1) set1.insert(num);
        for (auto num: nums2) set2.insert(num);
        unordered_set<int> result;
        for (auto num: set1) {
            if (set2.count(num) == 1)
                result.insert(num);
        }
        vector<int> _result;
        for (auto num: result) _result.push_back(num);
        return _result;
    }
};
