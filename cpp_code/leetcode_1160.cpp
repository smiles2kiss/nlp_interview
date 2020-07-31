class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (auto ch: s) map1[ch]++;
        for (auto ch: t) map2[ch]++;
        char result;
        for (auto item: map2) {
            char ch = item.first;
            int count = item.second;
            if (map1.find(ch) == map1.end() || map1[ch] != count) {
                result = ch;
                break;
            }
        }
        return result;
    }
};
