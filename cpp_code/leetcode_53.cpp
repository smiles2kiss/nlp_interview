#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> max;
        max.push_back(nums[0]);
        int max_sum = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] + max[i - 1] > nums[i]) {
                max.push_back(nums[i] + max[i - 1]);
            } else {
                max.push_back(nums[i]);
            }
            if (max[i] > max_sum) {
                max_sum = max[i];
            }
        }
        return max_sum;
    }
};

int main() {
	Solution solution;
	vector<int> data;
	data.push_back(-2);
	data.push_back(1);
	data.push_back(-3);
	data.push_back(4);
	data.push_back(-1);
	data.push_back(2);
	data.push_back(1);
	data.push_back(-5);
	data.push_back(4);
	
	int max_sum = solution.maxSubArray(data);
	cout << max_sum << endl;
	return 0;
}
