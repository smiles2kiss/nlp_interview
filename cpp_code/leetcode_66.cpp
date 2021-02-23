class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        int sum = 0;
        int len = digits.size();
        for (int i = len-1; i >= 0; i--) {
            sum = digits[i] + add;
            digits[i] = sum % 10;
            add = sum / 10;
        }
        if (add == 1) {
            vector<int> temp;
            temp.push_back(1);
            for (auto num:digits) temp.push_back(num);
            return temp;
        }
        return digits;
    }
};
