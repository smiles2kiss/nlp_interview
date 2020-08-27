class Solution {
public:
    unordered_set<int> nums;
    bool is_divided_by(int n, int count) {
        if (count == 1) {
            if (nums.find(n) != nums.end()) return true;
            else return false;
        }
        for (auto num: nums) {
            if (is_divided_by(n - num, count - 1))
                return true;
        }
        return false;
    }
    int numSquares(int n) {
        // Ì°ĞÄËã·¨
        int max_num = (int)sqrt(n);
        if (pow(max_num, 2) == n) return 1;

        for (int i = 1; i <= max_num; i++)
            nums.insert(pow(i, 2));
        for (int i = 1; i <= n; i++) {
            if (is_divided_by(n, i))
                return i;
        }
        return 0;
    }
};
