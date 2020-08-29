class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return "";
        int length = strs[0].size();
        for (int i = 0; i < length; i++) {
            char ch = strs[0][i];
            for (int j = 0; j < size; j++) {
                if (i == strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
