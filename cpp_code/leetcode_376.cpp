class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int max_count = 0;
        for (int start = 0; start < nums.size() - 1; start++) {
            int flag = 0;
            int count = 1;
            for (int end = start + 1; end < nums.size(); end++) {
                if (flag == 0) {
                    if (nums[end] > nums[end - 1]) {
                        count++;
                        flag = 1;
                    } else if (nums[end] < nums[end - 1]) {
                        count++;
                        flag = -1;
                    } else {
                        flag = 0;
                    }
                } else if (flag == 1) {
                    if (nums[end] < nums[end - 1]) {
                        count++;
                        flag = -1;
                    }
                } else if (flag == -1) {
                    if (nums[end] > nums[end - 1]) {
                        count++;
                        flag = 1;
                    }
                }
            }
            if (count > max_count)
                max_count = count;
        }
        return max_count;
    }
};
