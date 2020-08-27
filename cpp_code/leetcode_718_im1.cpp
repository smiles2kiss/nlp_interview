class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        int max_len = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int cur = 0;
                while (i + cur < len1 && j + cur < len2 && A[i + cur] == B[j + cur]) cur = cur + 1;
                if (cur > max_len) max_len = cur;
            }
        }
        return max_len;
    }
};
