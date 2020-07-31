class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> hash_table;
        int i = 0;
        int j = 0;
        int len = s.length();

        int max_len = 0;
        int count = 0;
        while (j < len) {
            hash_table[s[j]]++;
            if (hash_table[s[j]] == 1)
                count = count + 1;
            while (count > 2) {
                hash_table[s[i]]--;
                if (hash_table[s[i]] == 0)
                    count = count - 1;
                i++;
            }
            j++;
            max_len = max(max_len, j - i);
        }
        return max_len;
    }
};
