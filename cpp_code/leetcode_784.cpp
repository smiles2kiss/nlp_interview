class Solution {
public:
    vector<string> results;
    void dfs(string &S, int index) {
        int len = S.length();
        if (index == len) {
            results.push_back(S);
            return;
        }
        // ��ǰλ�ò�Ϊ�ַ�ʱ 
        dfs(S, index + 1);
        // ��ǰindexλ��Ϊ�ַ�ʱ
        if (isalpha(S[index])) {
            // ��Сдת��
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
