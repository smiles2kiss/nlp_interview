class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int left = -1, ans = 0;
        vector<int> map(128, -1);  // 记录左指针的位置
        for (int i = 0; i < len; i++) {
            left = max(left, map[s[i]]);
            map[s[i]] = i;
            ans = max(ans, i - left);
        }
        return ans;
    }
};
