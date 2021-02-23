class Solution {
public:
    // 带重复数字的所有排列
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int> nums, vector<bool> &used, int index) {
        int len = nums.size();
        if (index == len) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            if (i > 0 && !used[i-1] && nums[i] == used[i-1]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, index+1);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words.size();
        int count = 0;
        unordered_map<string, int> hash_table;
        unordered_map<int, string> hash_table1;
        vector<int> idx(len, 0);
        for (int i = 0; i < len; i++) {
            string word = words[i];
            if (!hash_table.empty() && hash_table.find(word) != hash_table.end()) {
                idx[i] = hash_table[word];
            }
            else {
                idx[i] = count;
                hash_table[word] = count;
                hash_table1[count] = word;
                count = count + 1;
            }
        }
        sort(idx.begin(), idx.end());
        vector<bool> used(idx.size(), false);
        dfs(idx, used, 0);
        
        vector<string> strs;
        for (int i = 0; i < res.size(); i++) {
            string temp = "";
            for (auto num:res[i]) temp += hash_table1[num];
            strs.push_back(temp);
        }

        for (auto str:strs) {
            
        }

        vector<int> result;
        return result;
    }
};
