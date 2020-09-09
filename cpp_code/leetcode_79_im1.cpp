class Solution {
public:
    bool dfs(vector<vector<char>> &board, int row, int col, string word, int idx) {
        int len1 = board.size();
        int len2 = board[0].size();
        if (row < 0 || row >= len1 || col < 0 || col >= len2) return false;
        if (word[idx] != board[row][col]) return false;
        if (idx == word.length() - 1)   return true;

        char temp = board[row][col];
        board[row][col] = '\0';

        bool res1 = dfs(board, row+1, col, word, idx+1);
        bool res2 = dfs(board, row-1, col, word, idx+1);
        bool res3 = dfs(board, row, col+1, word, idx+1);
        bool res4 = dfs(board, row, col-1, word, idx+1);
        if (res1 || res2 || res3 || res4) return true;
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len1 = board.size();
        int len2 = board[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
