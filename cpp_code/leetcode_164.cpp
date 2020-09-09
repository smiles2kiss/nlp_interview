class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;

        int mmin = INT_MAX;
        int mmax = -INT_MAX;
        for (auto num:nums) {
            mmin = min(mmin, num);
            mmax = max(mmax, num);
        }
        for (int i = 0; i < len; i++) 
            nums[i] = nums[i] - mmin;
        
        vector<int> hash_set(mmax - mmin + 1, 0);
        for (auto num:nums) hash_set[num] = 1;

        int pos = 0, res = 0;
        for (int i = 0; i < hash_set.size(); i++) {
            if (hash_set[i] == 1) {
                res = max(res, i - pos);
                pos = i;
            }
        }
        return res;
    }
};
