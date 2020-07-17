class Solution {
public:
    int half_find(vector<int> nums, int start, int end) {
        if (start == end)
            return start;
        int mid = (start + end) / 2;
        if (nums[mid] > nums[mid + 1])
            return half_find(nums, start, mid);
        else
            return half_find(nums, mid+1, end);
    }
    int findPeakElement(vector<int>& nums) {
        return half_find(nums, 0, nums.size() - 1);
    }
};
