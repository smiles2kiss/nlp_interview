class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if(stk.size() > 0) {
                if (
                    (stk.top() == '(' && s[i] == ')') || 
                    (stk.top() == '[' && s[i] == ']') || 
                    (stk.top() == '{' && s[i] == '}')
                ) {
                    stk.pop();
                } else {
                    stk.push(s[i]);
                }
            } else {
                stk.push(s[i]);
            }
        }

        if (stk.size() > 0)
            return false;
        else
            return true;
    }
};
