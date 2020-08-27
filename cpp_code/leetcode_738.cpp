class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string nums = to_string(N);
        int len = nums.size();
        int pos = len;
        int result;
        for (int i = len - 1; i >= 1; i--) {
            if (nums[i] < nums[i-1]) {
                pos = i;
                nums[i-1]--;
            }
        }
        while (pos < len) {
            nums[pos] = '9';
            pos++;
        }
        stringstream s(nums);
        s >> result;
        return result;
    }
};
