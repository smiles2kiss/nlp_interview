class Solution {
public:
    void merge(vector<pair<int, int>> &nums, vector<int> &count, int left, int mid, int right) {
        // 两个有序数组的合并
        vector<pair<int, int>> result;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i].first <= nums[j].first) {
            	count[nums[i].second] += j - mid - 1;
                result.push_back(nums[i]);
                i++;
            } else {
                result.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) { // 第i个值大于右边数组中的所有值 
            count[nums[i].second] += j - mid - 1;
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
    void merge_sort(vector<pair<int, int>> &nums, vector<int> &count, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        merge_sort(nums, count, left, mid);
        merge_sort(nums, count, mid + 1, right);
        merge(nums, count, left, mid, right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(len, 0);
        vector<pair<int, int>> items;
        for (int i = 0; i < len; i++) {
            items.push_back(make_pair(nums[i], i));
        }
        merge_sort(items, count, 0, len-1);
		return count;
    }
};
