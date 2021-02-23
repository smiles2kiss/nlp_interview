class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.length() == 0) return s;
        int count;

        string res1 = "";
        count = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                res1 = res1 + ch;
                count = count + 1;
            }
            else if (ch == ')') {
                if (count > 0) {
                    res1 = res1 + ch;
                    count = count - 1;
                }
            }
            else {
                res1 = res1 + ch;
            }
        }

        string res2 = "";
        count = 0;
        // ´ÓÓÒÏò×ó±éÀú
        for (int i = res1.length()-1; i >= 0; i--) {
            char ch = res1[i];
            if (ch == '(') {
                if (count < 0) {
                    res2 = ch + res2;
                    count = count + 1;
                }
            }
            else if (ch == ')') {
                res2 = ch + res2;
                count = count - 1;
            }
            else {
                res2 = ch + res2;
            }
        }
        return res2;
    }
};
