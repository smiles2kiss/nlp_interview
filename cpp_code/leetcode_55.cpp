#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
		int target = nums.size() - 1;
		int flag = 1;
		
		while (target > 0) {
			int temp = target;
			for (int i = 0; i < target; i++) {
				if (nums[i] + i >= target) {
					target = i;
					break;
				}
			}
			if (temp == target) {
				flag = 0;
				break;
			}
		}
		return flag; 
    }
};


int main() {
	vector<int> data;
	data.push_back(3);
	data.push_back(2);
	data.push_back(1);
	data.push_back(0); // delete or not
	data.push_back(2);
	data.push_back(3);
	data.push_back(1);
	data.push_back(1);
	data.push_back(4);
	
//	Solution solution;
//	int flag = solution.canJump(data);

	Solution *solution = new Solution();
	int flag = solution->canJump(data);
	cout << flag << endl;
	return 0;
} 
