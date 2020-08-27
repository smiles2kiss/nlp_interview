class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start < end) {
            int min_idx = start, _min = nums[start];
            int max_idx = start, _max = nums[start];
            for (int i = start; i <= end; i++) {
                if (nums[i] <= _min) {_min = nums[i]; min_idx = i;}
                if (nums[i] >= _max) {_max = nums[i]; max_idx = i;}
            }
            if(_min == nums[start] && _max == nums[end]) {
                start = start + 1;
                end = end - 1;
            }
            else if (_min == nums[start] && _max != nums[end]) 
                start = start + 1;
            else if (_min != nums[start] && _max == nums[end])
                end = end - 1;
            else
                break;
        }
        if (start < end)
            return end - start + 1;
        else
            return 0;
    }
};
