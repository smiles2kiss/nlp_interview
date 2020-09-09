class Solution {
public:
    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int i = left;
        int j = right;
        int key = nums[left];
        while (i < j) {
            while (i < j && key <= nums[j]) j--;
            nums[i] = nums[j];
            while (i < j && key >= nums[i]) i++;
            nums[j] = nums[i];
        }
        nums[i] = key;
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        // ¿ìËÙÅÅĞò
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
