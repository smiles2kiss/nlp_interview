class Solution {
public:
    vector<string> results;
    void dfs(string &S, int index) {
        int len = S.length();
        if (index == len) {
            results.push_back(S);
            return;
        }
        // 当前位置不为字符时 
        dfs(S, index + 1);
        // 当前index位置为字符时
        if (isalpha(S[index])) {
            // 大小写转换
            if (isupper(S[index])) S[index] = tolower(S[index]);
            else if (islower(S[index])) S[index] = toupper(S[index]);
            dfs(S, index + 1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return results;
    }
};
