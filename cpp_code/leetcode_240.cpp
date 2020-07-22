class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int row_len = matrix.size();
        int col_len = matrix[0].size();

        // ��ʼ�����½�
        int row = row_len - 1; // ��
        int col = 0;           // ��
        while (row >= 0 && col < col_len) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target){
                row--;
            } else {
                col++;
            }
        }
        return false;
    }
};
