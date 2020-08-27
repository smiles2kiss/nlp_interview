class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        int sum = 0;
        double avg = -10000;
        int n = nums.size();
        for (int left = 0; left < n; left++) {
            double sum = 0;
            for (int right = left; right < n; right++) {
                sum = sum + nums[right] * 1.0;
                int len = right - left + 1;
                if (len == k && sum / len > avg) avg = sum / len;
            }
        }
        return avg;
    }
};
