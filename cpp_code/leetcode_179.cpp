class Solution {
public:
    static bool compare(const string &a, const string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num:nums) strs.push_back(to_string(num));
        // sort(strs.begin(), strs.end(), greater());
        sort(strs.begin(), strs.end(), compare);
        string res;
        for (auto str:strs) res += str;
        return res[0] == '0' ? "0" : res;
    }
};
