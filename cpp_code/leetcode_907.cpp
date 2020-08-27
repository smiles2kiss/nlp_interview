class Solution {
public:
    // 如何找到所有连续子数组
    int _min(vector<int> &nums) {
        int mn = nums[0];
        for (auto num: nums) mn = min(num, mn);
        return mn;
    }
    int sumSubarrayMins(vector<int>& A) {
        int size = A.size();
        int sum = 0;
        for (int len = 1; len <= size; len++) {
            for (int i = 0; i <= size - len; i++) {
                vector<int> nums;
                for (int j = i; j < i + len; j++) nums.push_back(A[j]);
                sum = sum + _min(nums);
            }
        }
        return sum;
    }
};
