class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;

        int flag = 1;
        if (x < 0) flag = 0;
        long y = abs(x);

        vector<int> nums;
        while (y / 10 > 0) {
            nums.push_back(y % 10);
            y = y / 10;
        }
        nums.push_back(y);

        long res = 0;
        for (int i = 0; i < nums.size(); i++) res = res * 10 + nums[i];
        if (res > INT_MAX || res < -INT_MAX - 1) return 0;
        return flag == 0 ? -res : res;
    }
};
