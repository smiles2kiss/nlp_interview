class Solution {
public:
    bool visitedrow[9][9] = {false};
    bool visitedcol[9][9] = {false};
    bool visitedbox[9][9] = {false};
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int b = (i/3)*3+j/3;
                    visitedrow[i][num] = true;
                    visitedcol[j][num] = true;
                    visitedbox[b][num] = true;
                }
            }
        }
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col) {
        // 找到第一个未被填充的
        while (board[row][col] != '.') {
            col++;
            if (col >= 9) {row++; col = 0;}
            if (row >= 9) return true;
        }

        for (int i = 0; i < 9; i++) {
            int box = (row/3) * 3 + col/3;
            // 已经填充(行 || 列 || 方块)
            if (visitedrow[row][i] || visitedcol[col][i] || visitedbox[box][i])
                continue;
    
            board[row][col] = i + '1';
            visitedrow[row][i] = visitedcol[col][i] = visitedbox[box][i] = true;
            if (backtrack(board, row, col)) return true;
            else {
                // 回溯，无法填满
                board[row][col] = '.';
                visitedrow[row][i] = visitedcol[col][i] = visitedbox[box][i] = false;
            }
        }
        return false;
    }
};
