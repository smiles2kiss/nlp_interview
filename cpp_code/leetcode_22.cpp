class Solution {
public:
    vector<string> res;
    vector<char> temp;
    string char2string(char ch) {
        string str = " ";
        str[0] = ch;
        return str;
    }
    void dfs(int len, int idx1, int idx2) {
        // idx1代表当前字符串长度
        // idx2代表左括号与右括号的差值
        if (idx1 == 2*len) {
            if (idx2 != 0) return;
            string str = "";
            for (auto ch:temp) str += char2string(ch);
            res.push_back(str);
            return;
        }
        if (idx2 < 0) 
            return;
        else if (idx2 > 0) {
            temp.push_back(')');
            dfs(len, idx1+1, idx2-1);
            temp.pop_back();

            temp.push_back('(');
            dfs(len, idx1+1, idx2+1);
            temp.pop_back();
        }
        else {
            temp.push_back('(');
            dfs(len, idx1+1, idx2+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return res;
    }
};
