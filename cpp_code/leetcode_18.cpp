class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        if (nums.size() < 4)
            return results;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int a = 0; a <= n - 4; a++) {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            for (int b = a + 1; b <= n - 3; b++) {
                if (b > a + 1 && nums[b] == nums[b-1]) continue;
                int c = b + 1;
                int d = n - 1;
                while(c < d) {
                    if (nums[a] + nums[b] + nums[c] + nums[d] < target) 
                        c++;
                    else if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                        d--;
                    else {
                        results.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while(c < d && nums[c] == nums[c+1])
                            c++;
                        while(c < d && nums[d] == nums[d-1])
                            d--;
                        c++;
                        d--;
                    }
                }
            }
        }
        return results;
    }
};
