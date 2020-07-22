class Solution {
public:
    int getDigit(string src, int &ptr) {
        int k = 0;
        while (isdigit(src[ptr])) {
            k = k * 10 + (src[ptr] - '0');
            ptr++;
        }
        return k;
    }
    string dfs(string &src, int start, int end) {
        string ret;
        int i = start;
        while (i <= end) {
            if (isdigit(src[i])) {
                int num;
                num = getDigit(src, i);
                
                if (src[i] == '[')
                    i++;

                int k = i;
                int cnt = 1; // [
                while (k <= end) {
                    if (src[k] == '[') cnt++;
                    if (src[k] == ']') cnt--;
                    if (cnt == 0) break;
                    k++;
                }
                string temp = dfs(src, i, k - 1);
                for (int i = 0; i < num; i++) {
                    ret = ret + temp;
                }
                i = k + 1; // [的下一位
            }
            else if (isalpha(src[i])) {
                ret = ret + src[i];
                i++;
            }
        }
        return ret;
    }
    string decodeString(string s) {
        int len = s.length();
        return dfs(s, 0, len - 1);
    }
};
