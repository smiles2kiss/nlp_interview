class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> rows;
        unordered_map<char,int> cols;
        unordered_map<char,int> boxs;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int row_idx = i / 3;
                int col_idx = i % 3;
                int start_i = 3 * row_idx;
                int start_j = 3 * col_idx;
                int add_i = j / 3;
                int add_j = j % 3;
                int end_i = start_i + add_i;
                int end_j = start_j + add_j;

                char item1 = board[i][j];
                char item2 = board[j][i];
                char item3 = board[end_i][end_j];
                if (item1 != '.') rows[item1]++;
                if (item2 != '.') cols[item2]++;
                if (item3 != '.') boxs[item3]++;
                if (rows[item1] > 1) return false;
                if (cols[item2] > 1) return false;
                if (boxs[item3] > 1) return false;
            }
            rows.clear();
            cols.clear();
            boxs.clear();
        }
        return true;
    }
};
