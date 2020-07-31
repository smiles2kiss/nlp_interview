class Solution {
public:
    int longestPalindrome(string s) {
        // 统计字符出现的次数
        int max_len = 0;
        int flag = false;
        unordered_map<char, int> hash_map;
        // priority_queue<int, vector<int>, less<int>> q; // 大根堆
        for (auto ch: s) hash_map[ch]++;
        for (auto item: hash_map) {
            if (item.second % 2 == 0)
                max_len = max_len + item.second;
            else { 
                if (item.second > 2) 
                    max_len = max_len + item.second - 1;
                flag = true;
            }
        }
        if (flag) max_len = max_len + 1;
        return max_len;
    }
};
