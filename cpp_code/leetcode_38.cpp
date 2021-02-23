class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string previous = countAndSay(n-1);
        string result = "";
        int count = 1;
        int len = previous.length();
        for (int i = 0; i < len-1; i++) {
            if (previous[i] == previous[i+1]) {
                count = count + 1;
            } else {
                result += to_string(count) + previous[i];
                count = 1;
            }
        }
        result += to_string(count) + previous[len-1];
        return result;
    }
};
