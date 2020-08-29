class Solution {
public:
    string reverse(string str) {
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            char temp = str[i];
            str[i] = str[len-1-i];
            str[len-1-i] = temp;
        }
        return str;
    }

    string char2string(char ch) {
        string str = " ";
        str[0] = ch;
        return str;
    }

    string reverseWords(string s) {
        string result;
        string temp = "";
        for (auto ch:s) {
            if (ch == ' ') {
                if (temp.length() > 0) {
                    temp = reverse(temp);
                    result = result + temp;
                    temp = "";
                }
                result = result + char2string(ch);
            } else {
                temp = temp + char2string(ch);
            }
        }
        if (temp.length() > 0) {
            temp = reverse(temp);
            result = result + temp;
            temp = "";
        }
        return result;
    }
};
