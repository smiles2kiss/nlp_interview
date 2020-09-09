class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> hash_table;
        for (auto ch:s) hash_table[ch]++;
        if (hash_table.size() == 1) return true;
        int count = 0;
        for (auto item:hash_table) {
            if (item.second % 2 == 1) count++;
            else if (item.second != 2) return false;
        }
        return count <= 1 ? true : false;
    }
};
