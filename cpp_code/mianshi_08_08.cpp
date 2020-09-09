class Solution {
public:
    vector<string> strs;
    vector<char> temp;
    string char2string(char ch) {
        string str = " ";
        str[0] = ch;
        return str;
    }
    void dfs(vector<char> s, vector<bool> &used, int index) {
        int len = s.size();
        if (index == len) {
            string str = "";
            for (auto ch:temp) str += char2string(ch);
            strs.push_back(str);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            if (i > 0 && used[i-1] && s[i] == s[i-1]) continue;
            temp.push_back(s[i]);
            used[i] = true;
            dfs(s, used, index+1);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<string> permutation(string S) {
        int len = S.length();
        vector<bool> used(len, false);
        vector<char> chars;
        for (auto ch:S) chars.push_back(ch);
        sort(chars.begin(), chars.end());
        dfs(chars, used, 0);
        return strs;
    }
};
