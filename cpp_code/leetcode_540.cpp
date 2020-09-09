class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // ����ż���������ж�������
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid+1]) l = mid + 2;
            else r = mid;
        }
        return nums[l];
    }
};
