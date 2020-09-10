class Solution {
public:
    bool dfs(vector<vector<char>> &board, string word, int index, int row, int col) {
        int len1 = board.size();
        int len2 = board[0].size();
        if (index == word.length()) return true;
        if (row < 0 || row >= len1) return false;
        if (col < 0 || col >= len2) return false;
        if (board[row][col] != word[index]) return false;

        char temp = board[row][col];
        board[row][col] = '\0';
        bool res1 = dfs(board, word, index+1, row+1, col);
        bool res2 = dfs(board, word, index+1, row-1, col);
        bool res3 = dfs(board, word, index+1, row, col+1);
        bool res4 = dfs(board, word, index+1, row, col-1);
        if (res1 || res2 || res3 || res4) return true;
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len1 = board.size();
        int len2 = board[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (board[i][j] == word[0]) {
                    bool res = dfs(board, word, 0, i, j);
                    if (res) return true;
                }
            }
        }
        return false;
    }
};
