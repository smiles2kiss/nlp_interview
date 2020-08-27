class Solution {
public:
    string char2string(char ch) {
        string str = "-";
        str[0] = ch;
        return str;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int num = strs.size();
        if (num == 0) return result;

        int min_len = strs[0].length();
        for (int i = 1; i < num; i++) {
            int cur_len = strs[i].length();
            min_len = min(min_len, cur_len);
        }

        for (int i = 0; i < min_len; i++) {
            unordered_map<char, int> hash_table;
            for (int j = 0; j < num; j++) {
                char ch = strs[j][i];
                hash_table[ch]++;
            }
            if (hash_table.size() == 1) {
                result = result + char2string(strs[0][i]);
            } else {
                break;
            }
        }
        return result;
    }
};
