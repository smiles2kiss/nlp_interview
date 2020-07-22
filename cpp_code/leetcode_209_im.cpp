class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	// 双指针算法 
        int n = nums.size();
        int result = INT_MAX;
        if (n == 0)
            return 0;
        
        int start = 0;
        int end = 0;
        int sum = 0; // start到end段的和
        while (end < n) {
            sum = sum + nums[end];
            while (sum >= s) {
                // 丢弃前面的元素
                result = min(result, end - start + 1);
                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        return result == INT_MAX ? 0 : result;
    }
};
