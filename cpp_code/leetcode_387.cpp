class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash_table;
        for (auto ch: s) hash_table[ch]++;
        for (int i = 0; i < s.length(); i++) {
            if (hash_table[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
