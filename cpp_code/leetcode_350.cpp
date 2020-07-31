class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash_table1;
        unordered_map<int, int> hash_table2;
        for (auto num : nums1) hash_table1[num]++;
        for (auto num : nums2) hash_table2[num]++;
        vector<int> result;
        for (auto item: hash_table1) {
            int num = item.first;
            int count1 = item.second;
            int count2 = hash_table2[num];
            for (int i = 0; i < min(count1, count2); i++) result.push_back(num);
        }
        return result;
    }
};
