class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (nums[i] < len && nums[i] != i) {
                int idx = nums[i];
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == res) res++;
        }
        return res;
    }
};
