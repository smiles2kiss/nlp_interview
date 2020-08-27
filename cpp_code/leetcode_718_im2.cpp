class Solution {
public:
    int maxLength(vector<int> &A, vector<int> &B, int add_a, int add_b, int len) {
        int _max = 0, cur = 0;
        for (int i = 0; i < len; i++) {
            if (A[i + add_a] == B[i + add_b]) 
                cur = cur + 1;
            else
                cur = 0;
            _max = max(_max, cur);
        }
        return _max;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        
        int ans = 0;
        for (int i = 0; i < len1; i++) {
            int len = min(len1 - i, len2);
            int _max = maxLength(A, B, i, 0, len);
            ans = max(_max, ans);
        }
        for (int i = 0; i < len2; i++) {
            int len = min(len1, len2 - i);
            int _max = maxLength(A, B, 0, i, len);
            ans = max(_max, ans);
        }
        return ans;
    }
};
