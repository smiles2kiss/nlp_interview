class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp; 
    void dfs(vector<int> nums, vector<bool> &used, int len) {
        if (len == 0) {
            vector<int> res = temp;
            sort(res.begin(), res.end());
            if (find(results.begin(), results.end(), res) == results.end())
                results.push_back(res);
            return;
        }
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (used[i]) continue;
            if (i > 0 && !used[i-1] && nums[i-1] == nums[i]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, len - 1);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        for (int len = 0; len <= size; len++) {
            vector<bool> used(len, false);
            dfs(nums, used, len);
        }
        return results;
    }
};
