class Solution {
public:
    // row: 行数
    // col: 列数

    // 返回岛屿是否到达边界，标记遍历所有的岛屿
    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size()) return;
        if (col < 0 || col >= grid[0].size()) return;

        // 当前位置是海洋或者已经被访问过的陆地
        if (grid[row][col] != '1') return;

        // 当前位置是陆地，遍历当前位置
        grid[row][col] = '2'; // 标记为2表示已经被访问过
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int len1 = grid.size();
        int len2 = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] == '1') {
                    // 如果遍历完还未到达边界，则结果加1
                    res = res + 1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
