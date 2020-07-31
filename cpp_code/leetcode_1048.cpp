class Solution {
public:
    string longestDupSubstring(string S) {
        unordered_map<string, int> hash_table;
        int len = S.length();
        int max = 1;
        string max_substr = "";
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                string temp = S.substr(i, j);
                hash_table[temp]++;
                if (hash_table[temp] > max) {
                    max = hash_table[temp];
                    max_substr = temp;
                }
            }
        }
        return max_substr;
    }
};
