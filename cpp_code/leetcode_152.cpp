class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int imax = nums[0];
        int imin = nums[0];
        int ans  = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int mx = imax;
            int mn = imin;
            imax = max(nums[i], max(mx * nums[i], mn * nums[i]));
            imin = min(nums[i], min(mx * nums[i], mn * nums[i]));
            ans = max(imax, ans);
        }
        return ans;
    }
};
