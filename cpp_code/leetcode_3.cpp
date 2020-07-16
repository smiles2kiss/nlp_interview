class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();
        
        vector<char> cur;
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            int cur_len = 0;
            for (int j = i; j < s.length(); j++) {
                if (find(cur.begin(), cur.end(), s[j]) == cur.end()) {
                    cur_len = cur_len + 1;
                    cur.push_back(s[j]);
                } else {
                    break;
                }
            }
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            cur.clear();
        }
        return max_len;
    }
};
