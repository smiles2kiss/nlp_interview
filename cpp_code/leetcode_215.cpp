#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void Qsort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int i = left;
        int j = right;
        int key = nums[left];
        
        int temp;
        while (i < j) {
            // 大于key的元素，放在key的左边
            // 小于key的元素，放在key的右边
            while (i < j && nums[j] <= key) {
                j--;
            }
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            
            while (i < j && nums[i] >= key) {
                i++;
            }
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;	
        }
        Qsort(nums, left, i - 1);
        Qsort(nums, i + 1, right);
    }

    int findKthLargest(vector<int>& nums, int k) {
		int max_idx = nums.size() - 1;
		Qsort(nums, 0, max_idx);
		return nums[k - 1];
    }
};

int main() {
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);
	
	int k = 2;
	
	Solution solution;
	int result = solution.findKthLargest(nums, k);
	cout << result << endl;
	return 0;
} 
