class Solution {
public:
    vector<int> temp;
    vector<vector<int>> results;
    void dfs(vector<int> nums, vector<bool> &used, int index) {
        if (index == 0) {
            results.push_back(temp);
            return;
        }
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, index-1);
            temp.pop_back();
            used[i] = false;
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<bool> used(n, false);
        for (int i=1; i<=n; i++) nums.push_back(i);
        dfs(nums, used, n);
        string res = "";
        for (auto num:results[k-1]) res = res + to_string(num);
        return res;
    }
};
