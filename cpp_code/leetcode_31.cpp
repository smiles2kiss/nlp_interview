class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        int len = nums.size();
        while (pos > 0 && nums[pos] <= nums[pos-1]) pos--;
        cout << pos << endl;
        reverse(nums.begin() + pos, nums.end());
        if (pos > 0) {
            for(int start = pos; start < len; start++) { //寻找第一个大于nums[pos - 1]的数
                if (nums[start] > nums[pos-1]) {
                    swap(nums[start], nums[pos-1]);
                    break;
                }
            }
        }
    }
};
