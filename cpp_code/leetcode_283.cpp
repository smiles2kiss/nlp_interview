class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        for (auto num:nums) {
            if (num == 0) count = count + 1;
        }
        if (len == count) return;
        for (int i = 0; i < len; i++) {
            while (count > 0 && nums[i] == 0) {
                int j = i;
                while (j + 1 < len) {
                    nums[j] = nums[j+1];
                    j++;
                }
                nums[len-1] = 0;
                len = len - 1;
                count = count - 1;
            }
        }
    }
};
