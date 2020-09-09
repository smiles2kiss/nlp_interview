class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp; 
    vector<int> v;
    void dfs(int idx) {
        results.push_back(temp);
        if (idx == v.size()) return;

        for (int i = idx; i < v.size(); i++) {
            if (i > idx && v[i] == v[i-1]) continue;
            temp.push_back(v[i]);
            dfs(i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        v = nums;
        dfs(0);
        return results;
    }
};
