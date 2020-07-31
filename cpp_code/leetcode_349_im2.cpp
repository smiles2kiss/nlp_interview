class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> result;
        for (auto num: nums2) {
            // ��ѯ��ɾ��Ԫ��num
            if (set1.erase(num) == 1)
                result.push_back(num);
        }
        return result;
    }
};
