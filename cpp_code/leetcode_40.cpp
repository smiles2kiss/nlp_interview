class Solution {
public:
    vector<vector<int>> paths;
    vector<int> temp;
    void dfs(vector<int> &candidates, vector<bool> &used, int index, int target) {
        int len = candidates.size();
        if (target == 0) {
            vector<int> path = temp;
            sort(path.begin(), path.end());
            if (find(paths.begin(), paths.end(), path) == paths.end())
                paths.push_back(path);
            return;
        }
        if (target < 0) return;
        for (int i = index; i < len; i++) {
            if (used[i])
                continue;
            if (target > 0) {
                temp.push_back(candidates[i]);
                used[i] = true;
                dfs(candidates, used, i, target - candidates[i]);
                used[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();    
        vector<bool> used(len, false);
        dfs(candidates, used, 0, target);
        sort(paths.begin(), paths.end());
        return paths;
    }
};
