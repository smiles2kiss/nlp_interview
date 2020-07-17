class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        int start = 0;
        int end = nums.size() - 1; 
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target == nums[mid])
                return true;
            // 小技巧
            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }
            if (nums[start] < nums[mid]) {
                // 左边是连续数组
                if (target >= nums[start] && target < nums[mid]) 
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                // 右边是连续数组
                if (target >= nums[mid+1] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            } 
        }
        return false;
    }
};
