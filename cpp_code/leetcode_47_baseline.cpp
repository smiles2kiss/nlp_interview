class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp;
    vector<bool> used;
    void dfs(vector<int> &nums, vector<bool> &used, int count) {
        int len = nums.size();

        // µİ¹éÖÕÖ¹Ìõ¼ş
        if (count == len) {
            if (find(results.begin(), results.end(), temp) == results.end())
                results.push_back(temp);
            return;
        }

        for (int i = 0; i < len; i++) {
            if (used[i]) 
                continue;

            temp.push_back(nums[i]);

            used[i] = true;
            count = count + 1;

            dfs(nums, used, count);
            
            temp.pop_back();
            
            used[i] = false;
            count = count - 1;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0)
            return results;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len; i++) used.push_back(false);
        dfs(nums, used, 0); 
        return results;
    }
};
