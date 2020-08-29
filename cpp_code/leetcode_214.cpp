class Solution {
public:
    bool is_Palindrome(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) return false;
        }
        return true;
    }

    string char2string(char ch) {
        string str = " ";
        str[0] = ch;
        return str;
    }
    string shortestPalindrome(string s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            string str = "";
            for (int j = 0; j < i; j++) str += char2string(s[len-1-j]);
            str = str + s;
            if (is_Palindrome(str)) return str;
        }
        return "";
    }
};
