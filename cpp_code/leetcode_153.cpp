class Solution {
public:
    int half_find(vector<int> nums, int start, int end) {
        if (start == end)
            return nums[start];
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) // 最小值在右边
            return half_find(nums, mid+1, end);
        else 
            return half_find(nums, start, mid);
    }
    int findMin(vector<int>& nums) {
        return half_find(nums, 0, nums.size() - 1);
    }
};
