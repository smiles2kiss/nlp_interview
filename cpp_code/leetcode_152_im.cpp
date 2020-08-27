class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> imax(n, 1); imax[0] = nums[0];
        vector<int> imin(n, 1); imin[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            imax[i] = max(max(imax[i-1] * nums[i], imin[i-1] * nums[i]), nums[i]);
            imin[i] = min(min(imax[i-1] * nums[i], imin[i-1] * nums[i]), nums[i]);
            ans = max(imax[i], ans);
        }
        return ans;
    }
};
