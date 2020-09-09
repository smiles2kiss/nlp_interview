class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (auto row:rows) {
            for (int col = 0; col < len2; col++) matrix[row][col] = 0;
        }
        for (auto col:cols) {
            for (int row = 0; row < len1; row++) matrix[row][col] = 0;
        }
    }
};
