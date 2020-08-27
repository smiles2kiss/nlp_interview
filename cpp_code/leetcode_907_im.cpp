class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        vector<int> s;
        A.push_back(-40000);
        s.push_back(-1);

        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            while (s.back() != -1 && A[s.back()] >= A[i]) {
                int pos = s.back();
                s.pop_back();
                ans += A[pos] * (pos - s.back()) * (i - pos);
                ans %= 1000000007;
            }
            s.push_back(i);
        }
        return ans;
    }
};
