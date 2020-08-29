class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        string result;
        int i = 0;
        while (i < len) {
            int start = i;
            while (i < len && s[i] != ' ') i++;
            for (int j = start; j < i; j++) {
                result.push_back(s[start + i - 1 - j]);
            }
            while (i < len && s[i] == ' ') {
                result.push_back(' ');
                i++;
            }
        }
        return result;
    }
};
