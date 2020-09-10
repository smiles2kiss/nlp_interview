class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto num:nums) sum = sum + num;
        
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pre * 2 == sum - nums[i]) return i;
            pre = pre + nums[i];
        }
        return -1;
    }
};
