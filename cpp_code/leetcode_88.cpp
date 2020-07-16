class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int len1 = m;
        while(i < m+n && j < n) {
            if (nums1[i] <= nums2[j]) {
                i++;
            } else {
                // for (int k = len1 - 1; k >= i; k--) {
                //     nums1[k+1] = nums1[k];
                // }
                // nums1[i] = nums2[j];
                len1 = len1 + 1;
                nums1.insert(nums1.begin() + i, nums2[j]);
                nums1.pop_back();
                i++;
                j++;
            }
        }
        if (j < n) {
            for (int k = 0; k < n - j; k++) {
                nums1[len1 + k] = nums2[j + k];
            }
        }
    }
};
