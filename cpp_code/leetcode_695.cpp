class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int col) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        // �����Ƿ񵽴�߽�
        if (row < 0 || row >= len1) return 0; 
        if (col < 0 || col >= len2) return 0;

        // ��ʱδ�Ӵ����߽�
        if (grid[row][col] != 1) return 0;

        // ��Ƿ��ʹ��ĵ���
        grid[row][col] = 2;
        int res1 = dfs(grid, row + 1, col);
        int res2 = dfs(grid, row - 1, col);
        int res3 = dfs(grid, row, col + 1);
        int res4 = dfs(grid, row, col - 1);
        return res1 + res2 + res3 + res4 + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int res = 0;
        int len1 = grid.size();
        int len2 = grid[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j);
                    res = max(res, size);
                }
            }
        }

        return res;
    }
};
