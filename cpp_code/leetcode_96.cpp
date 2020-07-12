class Solution {
public:
    int numTrees(int n) {
        vector<int> nums;
        nums.push_back(1); // nums[0] = 1;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int k = 0; k <= i - 1; k++) {
                sum = sum + nums[k] * nums[i - 1 - k];
            }
            nums.push_back(sum);
        }
        return nums[n];
    }
};
