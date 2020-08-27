class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        if (n == 1) {
            if (k == 1) return costs[0][0];
            else {
                int mn = 1e5;
                for (int t = 0; t < k; t++) mn = min(mn, costs[0][t]);
                return mn;
            }
        }

        vector<int> pre(k, 0);
        vector<int> cur(k, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int mn = 1e5;
                for (int t = 0; t < k; t++) 
                    if (t != j) mn = min(mn, pre[t]);
                cur[j] = mn + costs[i][j];
            }
            for (int j = 0; j < k; j++) pre[j] = cur[j];
        }
        int mn = 1e5;
        for (int i = 0; i < k; i++) {
            if (cur[i] < mn) mn = cur[i];
        }
        return mn;
    }
};
