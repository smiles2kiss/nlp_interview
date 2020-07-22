class Solution {
public:
    unordered_map<char,string> phone{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> results;
    string current;
    void dfs(int depth, string digits) {
        int len = digits.length();
        if (depth == len) {
            results.push_back(current);
            return;
        }

        string chs = phone[digits[depth]];
        for (int i = 0; i < chs.size(); i++) {
            current.push_back(chs[i]);
            dfs(depth + 1, digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if (len == 0)
            return results;
        dfs(0, digits);
        return results;
    }
};
