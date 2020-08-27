class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        double sum = 0, max_sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) sum = sum + nums[i];
        max_sum = sum;
        for (int i = k; i < n; i++) {
            sum = sum + nums[i] - nums[i-k];
            max_sum = max(sum, max_sum);
        }
        return max_sum / k;
    }
};
