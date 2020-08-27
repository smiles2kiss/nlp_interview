class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L-1);
    }
    int count(vector<int> &A, int R) {
        int ans = 0, cur = 0;
        for (auto num : A) {
            cur = num <= R ? cur + 1: 0;
            ans = ans + cur;
        }
        return ans;
    }
};
