class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (nums[i] > 0 && nums[i] <= len && nums[i] != i+1 && nums[i] != nums[nums[i] - 1]) {
                int idx = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
            }
        }
        int res = 1;
        for (int i = 0; i < len; i++) {
            if (nums[i] == res) res++;
            else break;
        }
        return res;
    }
};
