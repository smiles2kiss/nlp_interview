class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int left, right, mid;
        
        // 查找左边界
        left = 0;
        right = len - 1;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] != target) return 0;
        int x = left;

        // 查找右边界
        right = len;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        int y = left;
        return y - x;
    }
};
