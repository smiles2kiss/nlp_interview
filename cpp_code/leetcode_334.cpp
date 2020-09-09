class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int l1 = INT_MAX, l2 = INT_MAX;
        for (auto num:nums) {
            if      (num <= l1) l1 = num;
            else if (num <= l2) l2 = num;
            else if (num >  l2) return true;
        }
        return false;
    }
};
