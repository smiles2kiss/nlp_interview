class Solution {
public:
    int count = 0;
    unordered_map<int, bool> hash_row;
    unordered_map<int, bool> hash_col;
    unordered_map<int, bool> hash_dia1;
    unordered_map<int, bool> hash_dia2;
    void dfs(int n, int idx) {
        if (idx == n) {
            count = count + 1;
            return;
        }
        
        for (int i = 0; i < n; i++) {
        	int j = idx;
            int sum1 = i + j;
            int sum2 = n-i+j;
            if (hash_row[i] || hash_col[i] || hash_dia1[sum1] || hash_dia2[sum2]) continue;
    		hash_row[i] = hash_col[i] = hash_dia1[sum1] = hash_dia2[sum2] = true;
            dfs(n, idx+1);
            hash_row[i] = hash_col[i] = hash_dia1[sum1] = hash_dia2[sum2] = false;
        }
    }
    int totalNQueens(int n) {
        for (int i = 0; i < n; i++) hash_row[i] = false; // 行
        for (int i = 0; i < n; i++) hash_col[i] = false; // 列
        for (int i = 0; i < 2*n; i++) hash_dia1[i] = false; // 左上到右下
        for (int i = 0; i < 2*n; i++) hash_dia2[i] = false; // 右上到左下 (取负数)
        dfs(n, 0);
        return count;
    }
};
