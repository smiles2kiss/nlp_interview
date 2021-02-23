class Solution {
public:
    vector<vector<vector<int>>> res;
    vector<vector<int>> temp;
    unordered_map<int, bool> hash_row;
    unordered_map<int, bool> hash_col;
    unordered_map<int, bool> hash_dia1;
    unordered_map<int, bool> hash_dia2;
    void dfs(int n, int idx) {
        if (idx == n) {
            res.push_back(temp);
            return;
        }
        
        for (int i = 0; i < n; i++) {
        	int j = idx;
            int sum1 = i + j;
            int sum2 = n-i+j;
            
            if (hash_row[i] || hash_col[i] || hash_dia1[sum1] || hash_dia2[sum2]) continue;
    		hash_row[i] = hash_col[i] = hash_dia1[sum1] = hash_dia2[sum2] = true;

            temp.push_back(vector<int>({i, j}));
            dfs(n, idx+1);
            temp.pop_back();
            
            hash_row[i] = hash_col[i] = hash_dia1[sum1] = hash_dia2[sum2] = false;
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) hash_row[i] = false; // 行
        for (int i = 0; i < n; i++) hash_col[i] = false; // 列
        for (int i = 0; i < 2*n; i++) hash_dia1[i] = false; // 左上到右下
        for (int i = 0; i < 2*n; i++) hash_dia2[i] = false; // 右上到左下 (取负数)
        dfs(n, 0);
        
        vector<vector<string>> results;
        for (int t = 0; t < res.size(); t++) {
        	vector<vector<char>> chm(n, vector<char>(n, '.'));
        	for (auto item:res[t]) {
        		int i = item[0];
				int j = item[1];
				chm[i][j] = 'Q';
			} 
			vector<string> res;
			for (int i = 0; i < chm.size(); i++) {
				string temp = "";
				for (auto ch:chm[i]) temp += ch;
				res.push_back(temp);
			}
			results.push_back(res);
		}
		return results;
    }
};
