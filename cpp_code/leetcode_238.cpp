class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        vector<int> results;
        int count = 0;
        for (auto num:nums) {
            if (num == 0) count++;
            else mul = mul * num;
        }

        for (auto num:nums) {
            if (count == 0) results.push_back(mul / num);
            else if (count == 1) {
                if (num == 0) results.push_back(mul);
                else results.push_back(0);
            }
            else results.push_back(0);
        }
        return results;
    }
};
