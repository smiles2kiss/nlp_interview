class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> answer({S});
        
        for (int i = 0; i < S.length(); i++) {
            if (isalpha(S[i])) {
                for (int j = answer.size() - 1; j >= 0; j--) {
                    answer.push_back(answer[j]); // ����һ���ַ���
                    // ��ǰ�ַ����͸��Ƶ��ַ�������S[j]λ�ñ��ִ�Сд�෴
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
