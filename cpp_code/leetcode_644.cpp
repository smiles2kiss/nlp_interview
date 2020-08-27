class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        double max_avg = -10000;
        int n = nums.size();
        for (int t = k; t <= n; t++) {
            double max_sum = 0, sum = 0;
            for (int i = 0; i < t; i++) sum = sum + nums[i];
            max_sum = sum;
            for (int i = t; i < n; i++) {
                sum = sum + nums[i] - nums[i-t];
                max_sum = max(sum, max_sum);
            }
            max_avg = max(max_sum / t, max_avg);
        }
        return max_avg;
    }
};
