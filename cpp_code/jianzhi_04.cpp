class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int columns = matrix[0].size();
        if (columns == 0) return false;

        int row = 0;
        int column = columns - 1;
        // 从左上角开始查找
        while (row < rows && column >= 0) {
            int num = matrix[row][column];
            if (num == target) return true;
            else if (num > target) column--;
            else row++;
        }
        return false;
    }
};
