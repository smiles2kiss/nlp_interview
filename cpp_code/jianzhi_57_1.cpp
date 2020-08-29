class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x = 0;
        int y = nums.size() - 1;
        while (x < y) {
            if (nums[x] + nums[y] == target) {
                return vector<int> {nums[x], nums[y]};
            } else if (nums[x] + nums[y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return vector<int> {};
    }
};
