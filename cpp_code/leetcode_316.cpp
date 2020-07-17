class Solution {
public:
    string removeDuplicateLetters(string s) {
                // 建立字典，统计剩余出现次数
        map<char, int> dict;
        for (int i = 0; i < s.length(); i++) {
            if (dict.find(s[i]) == dict.end())
                dict[s[i]] = 1;
            else
                dict[s[i]] = dict[s[i]] + 1;
        }

        vector<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (find(stack.begin(), stack.end(), s[i]) == stack.end()) {
                while(!stack.empty() && s[i] < stack.back() && dict[stack.back()] > 0)
                    stack.pop_back();
                stack.push_back(s[i]);
            }
            dict[s[i]] = dict[s[i]] - 1;
        }
        string result;
        for (int i = 0; i < stack.size(); i++)
            result = result + stack[i];
        return result;
    }
};
