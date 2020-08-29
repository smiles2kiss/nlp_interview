class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int left, right, ans = 0;
        for (int i = 0; i < len; i++) {
            // �Ե���ĸΪ����
            left = i, right = i;
            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
                ans++;
            } 
            // ��˫��ĸΪ����
            left = i, right = i + 1;
            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
                ans++;
            }
        }
        return ans;
    }
};
