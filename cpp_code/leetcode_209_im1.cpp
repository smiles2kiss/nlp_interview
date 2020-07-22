class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // »¬¶¯´°¿ÚËã·¨
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int sum = 0;
        int min_len = INT_MAX;
        int left = 0;
        for (int right = 0; right < n; right++) {
            sum = sum + nums[right];
            while (sum >= s) {
                min_len = min(min_len, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
