class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return s1 + s2 < s2 + s1;
    }
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num:nums) strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), cmp);
        string res = "";
        for (auto str:strs) res += str;
        return res;
    }
};
