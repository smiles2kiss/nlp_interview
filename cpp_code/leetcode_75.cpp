class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int lastTwoAt = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 2) nums[lastTwoAt++] = nums[i];
        }
        for (int i = lastTwoAt; i < len; i++) nums[i] = 2;

        int lastOneAt = 0;
        len = lastTwoAt;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 1) nums[lastOneAt++] = nums[i];
        }
        for (int i = lastOneAt; i < len; i++) nums[i] = 1;
    }
};
