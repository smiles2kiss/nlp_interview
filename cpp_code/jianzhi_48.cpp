class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> hash_map;
        while (i <= j && j < len) {
            char ch = s[j];
            hash_map[ch]++;
            j++;
            while (i < j && hash_map[ch] > 1) {
                char temp = s[i];
                hash_map[temp]--;
                if (hash_map[temp] == 0) 
                    hash_map.erase(hash_map.find(temp));
                i++;
            }
            ans = max(ans, (int)hash_map.size());
        }
        return ans;
    }
};
