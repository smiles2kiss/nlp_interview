class Solution {
public:
    int num = 0;
    vector<vector<int>> paths;
    vector<int> temp;
    void dfs(vector<int> coins, int amount) {
        if (amount < 0) return;
        if (amount == 0) {
            sort(temp.begin(), temp.end());
            if (find(paths.begin(), paths.end(), temp) == paths.end())
                paths.push_back(temp);
            return;
        }
        int len = coins.size();
        for (int i = 0; i < len; i++) {
            temp.push_back(coins[i]);
            dfs(coins, amount - coins[i]);
            temp.pop_back();
        }
    }
    int change(int amount, vector<int>& coins) {
        dfs(coins, amount);
        return paths.size();
    }
};
