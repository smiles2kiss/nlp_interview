class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int result = 0;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int _max = 0;
                for (int j = i; j < i+len; j++) _max = max(A[j], _max);
                if (_max >= L && _max <= R) result++;
            }
        }
        return result;
    }
};
