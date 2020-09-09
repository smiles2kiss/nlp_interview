class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int pre_num = nums[0];
        int pre_cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == pre_num) {
                if (pre_cnt < 2) pre_cnt = pre_cnt + 1;
                else {
                    nums.erase(nums.begin() + i);
                    i = i - 1;
                }
            } else {
                pre_num = nums[i];
                pre_cnt = 1;
            }
        }
        return nums.size();
    }
};
