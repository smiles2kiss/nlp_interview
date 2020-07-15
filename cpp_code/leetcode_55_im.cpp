class Solution {
public:
    bool canJump(vector<int>& nums) {
		int right_most = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i <= right_most) {
                right_most = max(right_most, i + nums[i]);
                if (right_most >= len - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
