class Solution {
public:
    bool halfSearch(vector<int> nums, int target, int start, int end) {
        int mid = (start + end) / 2;
        if (start <= mid) {
            if (target == nums[mid]) {
                return true;
            } else if (target < nums[mid]) {
                return halfSearch(nums, target, start, mid - 1);
            } else {
                return halfSearch(nums, target, mid + 1, end);
            }
        } else {
            return false;
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        // return halfSearch(nums, target, 0, nums.size() - 1);
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int result = n;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target <= nums[mid]) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};
