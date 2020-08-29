class Solution {
public:
    int hammingDistance(int x, int y) {
        queue<int> nums1, nums2;
        while (x / 2 > 0) {
            nums1.push(x % 2);
            x = x / 2;
        }
        nums1.push(x);
        while (y / 2 > 0) {
            nums2.push(y % 2);
            y = y / 2;
        }
        nums2.push(y);

        int mmax = max(nums1.size(), nums2.size());
        while (nums1.size() < mmax) nums1.push(0);
        while (nums2.size() < mmax) nums2.push(0);

        int ans = 0;
        while (mmax > 0) {
            if (nums1.front() != nums2.front()) ans++;
            nums1.pop();
            nums2.pop();
            mmax = mmax - 1;
        }
        return ans;
    }
};
