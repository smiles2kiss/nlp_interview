class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = (start + end) / 2;
            if (end > mid && nums[end] == nums[mid]) {
                end--;
                continue;
            }
            if (nums[mid] < nums[end]) // Á¬ĞøÉÏÉı 
                end = mid;
            else if (nums[mid] > nums[end]) 
                start = mid + 1;
        }
        return nums[start];
    }
};
