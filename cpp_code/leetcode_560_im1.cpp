class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] == k ? 1 : 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0; // 以i为起点
            for (int j = i; j < n; j++) {
                sum = sum + nums[j];
                if (sum == k) ans = ans + 1;
            }
        }
        return ans;
    }
};
