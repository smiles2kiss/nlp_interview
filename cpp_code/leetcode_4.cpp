class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int mid = (len1 + len2 + 1) / 2;
        
        int flag = 0;
        if ((len1 + len2) % 2 == 0) 
            flag = 1;
        
        if (len1 == 0 && len2 == 0)
            return 0;
        if (len1 == 0 && len2 != 0) {
            if (flag == 0)
                return nums2[len2/2];
            else 
                return (nums2[len2/2 - 1] + nums2[len2/2]) * 1.0 / 2;
        }
        if (len1 != 0 && len2 == 0) {
            if (flag == 0)
                return nums1[len1/2];
            else
                return (nums1[len1/2 - 1] + nums1[len1/2]) * 1.0 / 2;
        }
        
        int i = 0;
        int j = 0;
        int processed = 0;
        int first = nums1[0];
        int second = nums2[0];
        while (i < len1 && j < len2 && processed < mid) {
            if (nums1[i] <= nums2[j]) {
                first = nums1[i];
                if (i + 1 < len1)
                    second = min(nums1[i+1], nums2[j]);
                else
                    second = nums2[j];
                i++;
            }
            else {
                first = nums2[j];
                if (j + 1 < len2)
                    second = min(nums1[i], nums2[j+1]);
                else
                    second = nums1[i];
                j++;
            }
            processed++;
        }
        if (processed < mid) {
            while (i < len1 && processed < mid) {
                first = second;
                second = nums1[i+1];
                i++;
                processed++;
            } 
            while (j < len2 && processed < mid) {
                first = second;
                second = nums2[j+1];
                j++;
                processed++;
            }
        }
        if (flag == 0) 
            return first;
        else 
            return (first + second) * 1.0 / 2;
    }
};
