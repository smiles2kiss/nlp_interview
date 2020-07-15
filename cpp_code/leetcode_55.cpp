class Solution {
public:
    bool canJump(vector<int>& nums) {
		int target = nums.size() - 1;
		int flag = true;
		
		while (target > 0) {
			int temp = target;
			for (int i = 0; i < target; i++) {
				if (nums[i] + i >= target) {
					target = i;
					break;
				}
			}
			if (temp == target) {
				flag = false;
				break;
			}
		}
		return flag; 
    }
};
