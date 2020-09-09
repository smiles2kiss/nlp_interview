class Solution {
public:
    // 封闭岛屿必须上下左右周围全是水域
    bool dfs(vector<vector<int>> &grid, int row, int col) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        // 岛屿是否到达边界
        if (row < 0 || row >= len1) return true; 
        if (col < 0 || col >= len2) return true;

        // 此时未接触到边界
        if (grid[row][col] != 0) return false;

        // 标记访问过的岛屿
        grid[row][col] = 2;
        bool res1 = dfs(grid, row + 1, col);
        bool res2 = dfs(grid, row - 1, col);
        bool res3 = dfs(grid, row, col + 1);
        bool res4 = dfs(grid, row, col - 1);
        return res1 || res2 || res3 || res4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int res = 0;
        int len1 = grid.size();
        int len2 = grid[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] == 0) {
                    bool flag = dfs(grid, i, j);
                    // 搜索完后发现并没有接触到边界
                    if (!flag) res = res + 1;
                }
            }
        }

        return res;
    }
};
