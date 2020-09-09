class Solution {
public:
    string char2string(char ch) {
        string str = " ";
        str[0] = ch;
        return str;
    }
    vector<string> split(string s, char ch) {
        string temp = "";
        vector<string> strs;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ch && temp.length() > 0) {
                strs.push_back(temp); temp = "";
            }
            if (s[i] != ch) temp += char2string(s[i]);
        }
        if (temp.length() > 0) strs.push_back(temp);
        return strs;
    }
    int cnt(string s, int k) {
        if (s.length() < k) return 0;
        // 找到字符串中出现次数最少的字符
        unordered_map<char,int> hash_table;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int,char>>> q;
        for (auto ch:s) hash_table[ch]++;
        for (auto item:hash_table) q.push(make_pair(item.second, item.first));
        char ch = q.top().second;
        if (hash_table[ch] >= k) return s.length();

        int res = 0;
        vector<string> strs = split(s, ch);
        for (auto str:strs) res = max(res, cnt(str, k));
        return res;
    }
    int longestSubstring(string s, int k) {
        return cnt(s, k);
    }
};
