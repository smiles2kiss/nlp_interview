class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int remain = num.size() - k; // 需要保留remain个字符
        if (remain == 0)
            return "0";

        for (int i = 0; i < num.length(); i++) {
            while (k > 0 && !s.empty() && num[i] < s.top()) {
                s.pop();
                k = k - 1;
            }
            s.push(num[i]);
        }
        string result;
        while (!s.empty()) {
            result = s.top() + result;
            s.pop();
        }
        while (result.length() > 0 && result[0] == '0')
            result.erase(0, 1);

        if (result.length() == 0)
            return "0";
        else 
            return result.substr(0, remain);
    }
};
