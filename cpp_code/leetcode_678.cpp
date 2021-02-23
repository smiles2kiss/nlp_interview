class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        for (auto ch:s) {
            if (ch == '(' || ch == '*') left++;
            if (ch == ')') {
                if (left == 0) return false;
                left--;
            }
        }
        if (left == 0) return true;
        
        int right = 0;
        int len = s.length();
        for (int i = len-1; i >= 0; i--) {
            char ch = s[i];
            if (ch == '(') {
                if (right == 0) return false;
                right--;
            }
            if (ch == ')' || ch == '*') right++;
        }
        if (right == 0) return true;
        return true;
    }
};
