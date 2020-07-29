class Solution {
public:
    vector<string> results;
    string temp;
    vector<bool> used;
    string char2string(char ch) {
        string str = "-";
        str[0] = ch;
        return str;
    }
    void dfs(string &str, vector<bool> &used, int count) {
        int len = str.length();

        // µİ¹éÖÕÖ¹Ìõ¼ş
        if (count == len) {
            results.push_back(temp);
            return;
        }

        for (int i = 0; i < len; i++) {
            if (used[i]) 
                continue;
            if (i > 0 && str[i] == str[i-1] && !used[i-1])
                continue;

            temp = temp + char2string(str[i]);

            used[i] = true;
            count = count + 1;

            dfs(str, used, count);
            
            temp = temp.substr(0, temp.length() - 1);
            
            used[i] = false;
            count = count - 1;
        }
    }
    vector<string> permutation(string s) {
        int len = s.length();
        if (len == 0) return results;

        vector<int> chs;
        for (int i = 0; i < len; i++) chs.push_back(s[i]);
        sort(chs.begin(), chs.end());
        s = "";
        for (int i = 0; i < len; i++) s = s + char2string(chs[i]);

        for (int i = 0; i < len; i++) used.push_back(false);
        dfs(s, used, 0); 
        return results;
    }
};
