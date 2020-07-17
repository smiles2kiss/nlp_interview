class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int n = nums.size();
        vector<int> dp; // 从[0, i]的最大子序列的长度
        dp.push_back(1);
        int max_len = 1;
        for (int i = 1; i < n; i++) {
            int max_num = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // 转移方程的两个条件，nums[j] < nums[i]
                    max_num = max(max_num, dp[j]);
                }
            }
            dp.push_back(max_num + 1);
            max_len = max(max_len, max_num + 1);
        }
        return max_len;
    }
};
