class Solution {
public:
    vector<vector<string>> strs;
    vector<string> temp;
    bool is_reverse(string s) {
        int len = s.length(); 
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len-1-i]) return false;
        }
        return true;
    }
    void dfs(string s, int index) {
        int len = s.length();
        if (index == len) {
            strs.push_back(temp);
            return;
        }
        for (int i = index; i < len; i++) {
            string str = s.substr(index, i-index+1);
            bool flag = is_reverse(str);
            if (!flag) continue;
            temp.push_back(str);
			dfs(s, i+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return strs;
    }
};
