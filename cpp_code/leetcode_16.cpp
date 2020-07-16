class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int abs_dif = nums[n-1] + nums[n-2] + nums[n-3];
        int abs_sum = abs_dif;

        // ö��Ԫ��a
        for (int first = 0; first < n; first++) {
            if (first > 0 && nums[first] == nums[first-1])
                continue;
            
            // ö��Ԫ��b��c
            int second = first + 1;
            int third = n - 1;

            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target)
                    return sum;
                
                if (abs(sum - target) < abs(abs_sum - target)) {
                    abs_sum = sum;
                }

                if (sum == target)
                    return sum;
                else if (sum > target) {
                    // �ƶ�Ԫ��c
                    int third0 = third - 1;
                    while(second < third0 && nums[third0] == nums[third])
                        third0 = third0 - 1;
                    third = third0;
                } else {
                    // �ƶ�Ԫ��b
                    int second0 = second + 1;
                    while(second0 < third && nums[second0] == nums[second])
                        second0 = second0 + 1;
                    second = second0;
                }
            }
        }
        return abs_sum;
    }
};
