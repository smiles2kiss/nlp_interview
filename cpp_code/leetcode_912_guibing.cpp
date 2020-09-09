class Solution {
public:
    void merge(vector<int> &nums, int left, int mid, int right) {
        // 两个有序数组的合并
        vector<int> result;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                result.push_back(nums[i]);
                i++;
            } else {
                result.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            result.push_back(nums[i]);
            i++;
        }
        while (j <= right) {
            result.push_back(nums[j]);
            j++;
        }
        for (int i = 0; i < result.size(); i++) 
            nums[left + i] = result[i];
    }
    void merge_sort(vector<int> &nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // 采用归并排序
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
