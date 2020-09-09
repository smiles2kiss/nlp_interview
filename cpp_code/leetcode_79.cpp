class Solution {
public:
    bool dfs(vector<vector<char>> board, vector<vector<bool>> &used, int row, int col, string word, int idx) {
        int len1 = board.size();
        int len2 = board[0].size();
        if (idx >= word.length())   return true;
        if (row < 0 || row >= len1) return false;
        if (col < 0 || col >= len2) return false;
        if (used[row][col])         return false;
        if (board[row][col] == word[idx]) {
            used[row][col] = true;
            bool res1 = dfs(board, used, row+1, col, word, idx+1);
            bool res2 = dfs(board, used, row-1, col, word, idx+1);
            bool res3 = dfs(board, used, row, col+1, word, idx+1);
            bool res4 = dfs(board, used, row, col-1, word, idx+1);
            used[row][col] = false;
            return res1 || res2 || res3 || res4;
        } else {
            used[row][col] = true;
            bool res1 = dfs(board, used, row+1, col, word, idx);
            bool res2 = dfs(board, used, row-1, col, word, idx);
            bool res3 = dfs(board, used, row, col+1, word, idx);
            bool res4 = dfs(board, used, row, col-1, word, idx);
            used[row][col] = false;
            return res1 || res2 || res3 || res4;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len1 = board.size();
        int len2 = board[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                vector<vector<bool>> used(len1, vector<bool>(len2, false));
                if (board[i][j] == word[0] && dfs(board, used, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
