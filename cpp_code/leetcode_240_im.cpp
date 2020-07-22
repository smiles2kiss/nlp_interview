class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int row_len = matrix.size();
        int col_len = matrix[0].size();

        // 初始化左下角
        // 初始化右上角
        int row = 0;           // 行
        int col = col_len - 1; // 列
        while (row < row_len && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target){
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};
