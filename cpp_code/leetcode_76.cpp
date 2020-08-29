class Solution {
public:
    unordered_map<char, int> ori;
    unordered_map<char, int> cnt;
    bool check() {
        for (auto item:ori) {
            if (cnt[item.first] < item.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        for (auto ch:t) ori[ch]++;

        int left = 0, right = -1;
        int len = INT_MAX;
        int ansL = -1;
        int size = s.length();
        while (right < size) {
            right++;
            if (ori.find(s[right]) != ori.end()) {
                cnt[s[right]]++;
            }
            while (check() && left <= right) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    ansL = left;
                }
                if (ori.find(s[left]) != ori.end()) {
                    cnt[s[left]]--;
                }
                left++;
            }
        }
        return ansL == -1 ? "":s.substr(ansL, len);
    }
};
