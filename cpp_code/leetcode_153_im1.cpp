class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) // 最小值在右边
                start = mid + 1;
            else 
                end = mid;
        }
        return nums[start];
    }
};
