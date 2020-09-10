class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        int big   = -INT_MAX - 1;
        int mid   = -INT_MAX - 1;
        int small = -INT_MAX - 1;
        unordered_set<int> data;
        for (int i = 0; i < len; i++) {
            data.insert(nums[i]);
            if (nums[i] > big) {
                small = mid;
                mid = big;
                big = nums[i];
            }
            else if (nums[i] > mid && nums[i] < big) {
                small = mid;
                mid = nums[i];
            }
            else if (nums[i] > small && nums[i] < mid) {
                small = nums[i];
            }
        }
        if (data.size() < 3) return big;
        else return small;
    }
};
