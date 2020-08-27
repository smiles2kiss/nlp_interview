class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int left = 0;
        int times = 1;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            times = times * nums[right];
            while (times >= k) {
                times = times / nums[left];
                left++;
            }
            // right为右边界, [left, right]中的数为左边界的子数组个数
            ans += right - left + 1;
        }
        return ans;
    }
};
