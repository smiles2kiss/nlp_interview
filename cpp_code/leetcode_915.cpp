class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        unordered_map<int, int> hash_max;
        unordered_map<int, int> hash_min;
        int len = A.size();
        int mmax = -INT_MAX;
        int mmin = INT_MAX;
        for (int i = 0; i < len; i++) {
            mmax = max(A[i], mmax);
            hash_max[i] = mmax;
        }
        for (int i = len - 1; i >= 0; i--) {
            mmin = min(A[i], mmin);
            hash_min[i] = mmin;
        }

        int res = -1;
        for (int i = len - 1; i > 0; i--) {
            if (hash_min[i] >= hash_max[i-1]) res = i;
        }
        return res;
    }
};
