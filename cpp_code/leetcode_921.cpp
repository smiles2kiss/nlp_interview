class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        for (auto ch:S) {
            if (ch == '(') stk.push(ch);
            if (ch == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else stk.push(ch);
            }
        }
        return stk.size();
    }
};
