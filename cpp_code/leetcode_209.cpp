class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int n = nums.size();
        vector<int> sums(n+1, 0);
        // sums[0] = 0
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i-1] + nums[i-1];
        for (int i = 1; i <= n; i++) {
            
        }
    }
};
