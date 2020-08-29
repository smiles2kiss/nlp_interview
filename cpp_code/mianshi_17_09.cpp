class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> ans(k, 1);
        int pa = 0, pb = 0, pc = 0;
        for (int i = 1; i < k; i++) {
            ans[i] = min(min(ans[pa] * 3, ans[pb] * 5), ans[pc] * 7);
            if (ans[pa] * 3 == ans[i]) pa++;
            if (ans[pb] * 5 == ans[i]) pb++;
            if (ans[pc] * 7 == ans[i]) pc++;
        }
        return ans[k-1];
    }
};
