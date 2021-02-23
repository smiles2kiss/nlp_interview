class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void nextPermutation(vector<int>& nums) {
        // [5,6,11,9,7,5,3,1]
        // 找到第一个大于前一个数字的位置,idx=2, num=11
        int len = nums.size();
        int idx = -1;
        for (int i = len-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 从2到尾部的序列中，找到第一个大于6的值
        int pos = idx;
        for (int i = len-1; i >= idx; i--) {
            if (nums[i] > nums[idx-1]) {
                pos = i;
                break;
            }
        }
        
        // 交换7和6两个元素
        swap(nums[idx-1], nums[pos]);
        // 将11之后的元素重新按照升序排列
        sort(nums.begin() + idx, nums.end());
    }
};
