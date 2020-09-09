class Solution {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0, n);
        for (int i = 1; i < k; i++) next_permutation(s.begin(), s.end());
        return s;
    }
};
