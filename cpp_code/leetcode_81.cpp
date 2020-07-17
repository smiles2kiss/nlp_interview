class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        int start = 0;
        int end = nums.size() - 1; 
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target == nums[mid])
                return true;
            // С����
            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }
            if (nums[start] < nums[mid]) {
                // �������������
                if (target >= nums[start] && target < nums[mid]) 
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                // �ұ�����������
                if (target >= nums[mid+1] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            } 
        }
        return false;
    }
};
