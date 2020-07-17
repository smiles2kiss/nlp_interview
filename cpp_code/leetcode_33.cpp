class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int result = - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[start] <= nums[mid]) {
                // 左边数组是有序的
                if (target < nums[start] || target > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            } else {
                // 右边数组是有序的
                if (target < nums[mid] || target > nums[end]) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};
