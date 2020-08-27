class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        unordered_map<int, int> hash_table;
        for (int i = 0; i < len2; i++) {
            hash_table[nums2[i]] = i;
        }
        for (auto num: nums1) {
            int idx2 = hash_table[num];
            int data = -1;
            for (int i = idx2 + 1; i < len2; i++) {
                if (nums2[i] > num) {
                    data = nums2[i];
                    break;
                }
            }
            result.push_back(data);
        }
        return result;
    }
};
