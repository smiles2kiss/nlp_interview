class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> nums1, nums2;
        int len1 = a.length();
        int len2 = b.length();
        for (int i = len1-1; i >= 0; i--) nums1.push_back((int)(a[i] - '0'));
        for (int i = len2-1; i >= 0; i--) nums2.push_back((int)(b[i] - '0'));
        if (len1 < len2) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int mmax = max(len1, len2);
        int mmin = min(len1, len2);
        int add = 0;
        int sum = 0;
        for (int i = 0; i < mmin; i++) {
            sum = nums1[i] + nums2[i] + add;
            add = sum / 2;
            sum = sum % 2;
            nums1[i] = sum;
        }
        for (int i = mmin; i < mmax; i++) {
            sum = nums1[i] + add;
            add = sum / 2;
            sum = sum % 2;
            nums1[i] = sum;
        }
        if (add == 1) nums1.push_back(add);
        reverse(nums1.begin(), nums1.end());
        string res = "";
        for (auto num:nums1) res += to_string(num);
        return res;
    }
};
