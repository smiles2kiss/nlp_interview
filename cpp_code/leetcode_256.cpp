class Solution {
public:
    // 三个数组合起来和为k
    vector<vector<int>> paths;
    vector<int> temp;
    void dfs(vector<int> &candidates, vector<bool> &used, int index, int target, int n) {
        int len = candidates.size();
        if (target == 0) {
            vector<int> path = temp;
            sort(path.begin(), path.end());
            if (temp.size() == n && find(paths.begin(), paths.end(), path) == paths.end()) 
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
                dfs(candidates, used, i, target - candidates[i], n);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates({1, 2, 3, 4, 5, 6, 7, 8, 9});
        int len = candidates.size();
        vector<bool> used(len, false);
        dfs(candidates, used, 0, n, k);
        return paths;
    }
};
