class Solution {
public:
    vector<string> ans;
    bool isvalid(string s) {
        int count = 0;
        for (auto ch:s) {
            if (ch == '(') count = count + 1;
            if (ch == ')') count = count - 1;
            if (count < 0) return false;
        }
        return count == 0 ? true : false;
    }
    void dfs(string str, int start, int left, int right) {
        if (left == 0 && right == 0) {
            if (isvalid(str)) ans.push_back(str);
            return;
        }
        int len = str.length();
        for (int i = start; i < len; i++) {
            if (i != start && str[i] == str[i-1]) continue;
            if (str[i] == '(' && left > 0) {
                // …æ≥˝◊Û¿®∫≈
                dfs(str.substr(0, i) + str.substr(i+1, len-i-1), i, left-1, right);
            }
            if (str[i] == ')' && right > 0) {
                // …æ≥˝”“¿®∫≈
                dfs(str.substr(0, i) + str.substr(i+1, len-i-1), i, left, right-1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        // left ∫Õ right±Ì æ◊Û”“¿®∫≈“™…æ≥˝µƒ∏ˆ ˝
        int left = 0;
        int right = 0;
        for (auto ch:s) {
            if (ch == '(') left++;
            if (ch == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        dfs(s, 0, left, right);
        return ans;
    }
};
