class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> hash_table_s, hash_table_t;
        int start_s = 0, start_t = 0;
        for (auto ch:s) {
            if (hash_table_s.find(ch) == hash_table_s.end()) {
                hash_table_s[ch] = start_s;
                start_s++;
            }
        }
        for (auto ch:t) {
            if (hash_table_t.find(ch) == hash_table_t.end()) {
                hash_table_t[ch] = start_t;
                start_t++;
            }
        }
        string res_s = "", res_t = "";
        for (auto ch:s) res_s = res_s + to_string(hash_table_s[ch]);
        for (auto ch:t) res_t = res_t + to_string(hash_table_t[ch]);
        return res_s == res_t ? true : false;
    }
};
