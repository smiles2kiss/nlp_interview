class Solution {
public:
    // 找出所有区域的个数
    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &used, int row, int col) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        if (row == 0 || row == len1 - 1 || col == 0 || col == len2 - 1)
            return grid[row][col] == 'O' ? true : false;
        if (used[row][col]) return false;

        // 此时未接触到边界
        if (grid[row][col] != 'O') return false;

        // 标记访问过的岛屿
        used[row][col] = true;
        bool res1 = dfs(grid, used, row + 1, col);
        bool res2 = dfs(grid, used, row - 1, col);
        bool res3 = dfs(grid, used, row, col + 1);
        bool res4 = dfs(grid, used, row, col - 1);
        return res1 || res2 || res3 || res4;
    }
    void color(vector<vector<char>> &grid, int row, int col) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        if (row < 0 || row >= len1) return;
        if (col < 0 || col >= len2) return;
        if (grid[row][col] != 'O') return;
        else {
            grid[row][col] = 'X';
            color(grid, row+1, col);
            color(grid, row-1, col);
            color(grid, row, col+1);
            color(grid, row, col-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int len1 = board.size();
        int len2 = board[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (board[i][j] == 'O') {
                    vector<vector<bool>> used(len1, vector<bool>(len2, false));
                    bool flag = dfs(board, used, i, j);
                    if (!flag) color(board, i, j);
                }
            }
        }
        
    }
};
