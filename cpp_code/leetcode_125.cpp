class Solution {
public:
    char conv_char_upper(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        return ch;
    }
    bool is_char(char ch) {
        if (
                (ch >= '0' && ch <= '9') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z')
            ) 
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        if (s.size() < 2)
            return true;

        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            while (!is_char(s[i]) && i < j)
               i++;
            while (!is_char(s[j]) && i < j)
               j--;
            if (i != j && is_char(s[i]) && is_char(s[j])) {
                char ch1 = conv_char_upper(s[i]);
                char ch2 = conv_char_upper(s[j]);
                if (ch1 != ch2) {
                    return false;
                }
            }
            
            i++;
            j--;
        }
        return true;
    }
};
