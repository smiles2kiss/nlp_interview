class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        for (auto num: nums1) set1.insert(num);
        for (auto num: nums2) set2.insert(num);
        set<int> result;
        for (auto num1: set1) {
            for (auto num2: set2) {
                if (num1 == num2) {
                    result.insert(num1);
                }
            }
        }
        vector<int> _result;
        for (auto num: result) _result.push_back(num);
        return _result;
    }
};
