class Solution {
public:
    vector<vector<int>> paths;
    vector<int> temp;
    void dfs(vector<int> &candidates, int index, int target) {
        int len = candidates.size();
        if (target == 0) {
            paths.push_back(temp);
            return;
        }
        if (target < 0) return;
        for (int i = index; i < len; i++) {
            if (target > 0) {
                temp.push_back(candidates[i]);
                dfs(candidates, i, target - candidates[i]);
                temp.pop_back();
            }
        }
    }

    int choices(vector<int>& candidates, int target) {
        // 完全背包问题
        // 判断有多少种方法可以装满背包
        // 状态: dp[i][j] 表示前i个元素，当背包容量为j时，存在dp[i][j]种方法可以装背包

        int len = candidates.size();
        int choices = 0;
        if (len == 0) {
            if (target == 0)
                choices = 1;
            else
                choices = 0;
        }
        vector<vector<int>> dp;
        for (int i = 0; i <= len; i++) {
            vector<int> temp(target + 1, 0);
            dp.push_back(temp);
        }

        for (int i = 1; i <= len; i++) {
            // 当背包容量为0时，所有元素都可以不选
            dp[i][0] = 1;
        }
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= candidates[i-1]) {
                    // 选nums[i-1]放入背包 dp[i][j - nums[i-1]] 
                    // 不选nums[i-1]放入背包 dp[i-1][j]
                    dp[i][j] = dp[i-1][j] + dp[i][j - candidates[i-1]];
                } else {
                    // 
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        choices = dp[len][target];
        return choices;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return paths;
    }
};
