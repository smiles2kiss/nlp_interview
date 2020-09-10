class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= k; j++) {
                if (i + j < len) {
                    if (nums[i] >=  INT_MAX   && nums[i+j] < 0) continue;
                    if (nums[i] <= -INT_MAX-1 && nums[i+j] > 0) continue;
                    if (nums[i] < 0 && nums[i+j] >=  INT_MAX)   continue;
                    if (nums[i] > 0 && nums[i+j] <= -INT_MAX-1) continue;
                    if (abs(nums[i] - nums[i+j] <= t) return true;
                }
            }
        }
        return false;
    }
};
