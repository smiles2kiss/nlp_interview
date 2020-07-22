class Solution {
public:
    string char2str(char ch) {
        string str = "-";
        str[0] = ch;
        return str;
    }
    int string2int(string num) {
        int k = 0;
        int len = num.length();
        for (int i = 0; i < len; i++) {
            k = k * 10 + (num[i] - '0');
        }
        return k;
    }
    string decodeString(string s) {
        if (s.size() == 0)
            return s;

        int pre_type = 3;
        int len = s.length();
        vector<string> stk;
        for (int i = 0; i < len; i++) {
            if (s[i] == '[') {
                stk.push_back(char2str(s[i]));
                pre_type = 0;
            }
            else if (isdigit(s[i])) {
                if (pre_type == 1) {
                    int idx = stk.size() - 1;
                    stk[idx] = stk[idx] + char2str(s[i]);
                } else {
                    stk.push_back(char2str(s[i]));
                }
                pre_type = 1;
            } 
            else if (isalpha(s[i])) {
                if (pre_type == 2) {
                    int idx = stk.size() - 1;
                    stk[idx] = stk[idx] + char2str(s[i]);
                } else {
                    stk.push_back(char2str(s[i]));
                }
                pre_type = 2;
            }
            else if (s[i] == ']') {
                int len = stk.size();
                string str = stk[len - 1];
                string lbr = stk[len - 2];  // [
                string num = stk[len - 3];
                stk.pop_back(); // µ¯³östr 
                stk.pop_back(); // µ¯³ö[
                stk.pop_back(); // µ¯³önum 

                string ret;
                int cnt = string2int(num);
                for (int i = 0; i < cnt; i++) {
                    ret = ret + str;
                }
                if (stk.empty())
                    stk.push_back(ret);
                else {
                    int len = stk.size();
                    if (stk[len-1] != "[") 
                        stk[len - 1] = stk[len - 1] + ret;
                    else
                        stk.push_back(ret);
                }
                pre_type = 2;
            }
        }
        if (stk.size() > 1) {
            while (stk.size() != 1) {
                string ret = stk.back();
                stk.pop_back();
                stk[stk.size() - 1] = stk[stk.size() - 1] + ret;
            }
        }
        string result = stk.back();
        return result;
    }
};
