class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int ans = 0;
        for (int i = 0; i < 2 * len - 1; i++) {
            int left = i / 2;
            int right = i / 2 + i % 2;
            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
                ans++;
            }
        }
        return ans;
    }
};
