class Solution {
public:
	// ×´Ì¬Ñ¹Ëõ 
    vector<int> sums;
    vector<bool> used;
    int square_side;
    bool dfs(vector<int> &nums, int index, int num_idx) {
        int len = nums.size();
        if (sums[num_idx] == square_side){
            if (num_idx < 3)
                return dfs(nums, 0, num_idx + 1);
            else 
                return true;
        }
        if (index > len) 
            return false;
        
        for (int i = index; i < len; i++) {
            if (sums[num_idx] + nums[i] <= square_side) {\
                if (used[i])
                    continue;
                sums[num_idx] = sums[num_idx] + nums[i];
                used[i] = true;
                if (dfs(nums, i + 1, num_idx))
                    return true;
                sums[num_idx] = sums[num_idx] - nums[i];
                used[i] = false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return false;

        int sum = 0;
        for (auto num: nums) sum += num;
        if (sum % 4 != 0)
            return false;

        vector<int> _sums(4, 0);
        vector<bool> _used(len, false);
        sums = _sums;
        used = _used;

        square_side = sum / 4;
        sort(nums.rbegin(), nums.rend());
        bool result1 = dfs(nums, 0, 0);
       
        if (result1)
            return true;
        else
            return false;
    }
};
