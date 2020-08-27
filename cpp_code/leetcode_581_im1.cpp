class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (temp[i] != nums[i] && start == -1) start = i;
            if (temp[i] != nums[i]) end = i;
        }
        if (start == -1 && end == -1) return 0;
        else return end - start + 1;
    }
};
