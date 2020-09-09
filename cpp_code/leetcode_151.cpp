class Solution {
public:
    string char2string(char ch) {
        string str = " ";
        str[0] = ch;
        return str;
    }
    string reverseWords(string s) {
        string temp = "";
        vector<string> strs;
        int flag = 0;
        for (auto ch:s) {
            if (ch == ' ') {
                if (flag == 1) continue;
                if (temp.length() > 0) {
                    strs.push_back(temp);
                    temp = "";
                }
                flag = 1;
            } 
            else {
                temp += char2string(ch);
                flag = 0;
            }
        }
        if (temp.length() > 0) 
            strs.push_back(temp);

        string res = "";
        while (!strs.empty()) {
            res = res + strs.back();
            strs.pop_back();
            if (strs.size() > 0) res += " ";
        }
        return res;
    }
};
