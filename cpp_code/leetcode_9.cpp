class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        vector<int> nums;
        while (x / 10 > 0) {
            nums.push_back(x % 10);
            x = x / 10;
        }
        nums.push_back(x);

        int len = nums.size();
        for (int i = 0; i < len / 2; i++) {
            if (nums[i] != nums[len-1-i]) return false;
        }
        return true;
    }
};
