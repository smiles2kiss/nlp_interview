class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroAt = 0;
        for (auto num:nums) {
            if (num != 0) {
                nums[lastNonZeroAt] = num; lastNonZeroAt++;
            }
        }
        for (int i = lastNonZeroAt; i < nums.size(); i++) nums[i] = 0;
    }
};
