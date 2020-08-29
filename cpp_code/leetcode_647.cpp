class Solution {
public:
    bool is_string(string str) {
        int len = str.length();
        if (len == 1) return true;
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int size = s.length();
        vector<string> results;
        for (int len = 1; len <= size; len++) {
            for (int start = 0; start <= size - len; start++) {
                string sub = s.substr(start, len);
                if (is_string(sub)) results.push_back(sub); 
            }
        }
        return results.size();
    }
};
