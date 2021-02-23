class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        if (len == 0) return s;

        stack<int> stk;
        vector<int> sarr(len, 0); // 记录无效位置
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else sarr[i] = 1;
            }
        }

        while (!stk.empty()) {
            sarr[stk.top()] = 1;
            stk.pop();
        }

        string res = "";
        for (int i = 0; i < len; i++) {
            if (sarr[i] == 0) res += s[i];
        }
        return res;
    }
};
