class Solution {
public:
    string smallestSubsequence(string text) {
        // 建立字典，统计剩余出现次数
        map<char, int> dict;
        for (int i = 0; i < text.length(); i++) {
            if (dict.find(text[i]) == dict.end())
                dict[text[i]] = 1;
            else
                dict[text[i]] = dict[text[i]] + 1;
        }

        vector<char> s;
        for (int i = 0; i < text.length(); i++) {
            if (find(s.begin(), s.end(), text[i]) == s.end()) {
                while(!s.empty() && text[i] < s.back() && dict[s.back()] > 0)
                    s.pop_back();
                s.push_back(text[i]);
            }
            dict[text[i]] = dict[text[i]] - 1;
        }
        string result;
        for (int i = 0; i < s.size(); i++)
            result = result + s[i];
        return result;
    }
};
