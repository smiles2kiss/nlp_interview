class Solution {
public:
    vector<vector<int>> results;
    vector<bool> used;
    vector<int> path;
    void dfs(int depth, vector<int> nums) {
        int len = nums.size();
        if (path.size() >= 2)
            results.push_back(path);
        if (depth == len) 
            return;

        // unordered_set<int> s; // 集合
        unordered_map<int,int> map1; // 哈希表
        for (int i = depth; i < len; i++) {
            // 哈希表去重
            if (map1.find(nums[i]) != map1.end())
                continue;
            if (path.size() > 0 && nums[i] < path[path.size() - 1])
                continue;
            // s.insert(nums[i]);
            map1[nums[i]] = 1;
            path.push_back(nums[i]);
            dfs(i + 1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return results;
        vector<bool> _used(len, false);
        used = _used;
        // sort(nums.begin(), nums.end());
        dfs(0, nums);
        return results;
    }
};
