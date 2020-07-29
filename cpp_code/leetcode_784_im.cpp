class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> answer({S});
        
        for (int i = 0; i < S.length(); i++) {
            if (isalpha(S[i])) {
                for (int j = answer.size() - 1; j >= 0; j--) {
                    answer.push_back(answer[j]); // 复制一个字符串
                    // 当前字符串和复制的字符串，在S[j]位置保持大小写相反
                    if (isupper(answer[j][i]))
                        answer[j][i] = tolower(answer[j][i]);
                    else
                        answer[j][i] = toupper(answer[j][i]);
                }
            }
        }
        return answer;
    }
};
