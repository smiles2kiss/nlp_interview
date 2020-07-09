#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Qsort(vector<int> &nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }

        int i = left;
        int j = right;
        int key = nums[left];
        
        int temp;
        while (i < j) {
            // 大于key的元素，放在key的左边
            // 小于key的元素，放在key的右边

            while (i < j && nums[j] < key) {
                j--;
            }
            // 某个位置大于key时
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            while (i < j && nums[i] >= key) {
                i++;
            }
            // 某个位置小于k时 
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        if (i == k) {
        	return nums[k];
		} else if (i > k) {
			return Qsort(nums, left, i - 1, k);
		} else {
			return Qsort(nums, i + 1, right, k);
		}
    }

    int findKthLargest(vector<int> &nums, int k) {
		int max_idx = nums.size() - 1;
		int kth = Qsort(nums, 0, max_idx, k - 1);
		return kth;
    }
};

int main() {
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(6);
	int k = 4;
	
	Solution solution;
	int result = solution.findKthLargest(nums, k);
	cout << result << endl;
	return 0;
} 
