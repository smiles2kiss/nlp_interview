class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        if (len < 2) return len;

        int pre = 0, cur = 0, ans = 1;
        for (int i = 1; i < len; i++) {
            if (A[i] > A[i-1]) { // 1
                if (pre == -1) cur = cur + 1;
                else cur = 2;
                pre = 1;
            }
            else if (A[i] < A[i-1]) { // -1
                if (pre == 1) cur = cur + 1;
                else cur = 2;
                pre = -1;
            }
            else {
                cur = 1;
                pre = 0;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
