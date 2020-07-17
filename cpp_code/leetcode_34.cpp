class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return vector({-1, -1});
        if (target < nums[0] || target > nums[nums.size() - 1])
            return vector({-1, -1});

        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (nums[i] < target) 
                i++;
            if (nums[j] > target)
                j--;
            if (nums[i] == target && nums[j] == target)
                break;
        }
        if (nums[i] != target) 
            return vector({-1, -1});
        else
            return vector({i, j});
    }
};
