class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int column = matrix.size();
        if (column == 0)
            return false;
        int row = matrix[0].size();
        if (row == 0)
            return false;

        int back_start = 0;
        int back_end = column - 1;
        while (back_start <= back_end) {
            int mid = (back_start + back_end) / 2;
            if (target == matrix[back_start][row-1]) 
                return true;
            if (target == matrix[mid][row-1])
                return true;
            if (target == matrix[back_end][row-1])
                return true;
            if (target < matrix[back_start][row-1]) 
                back_end = back_start - 1;
            else if (target > matrix[back_start][row-1] && target < matrix[mid][row-1]){
                back_end = mid - 1;
            } else
                back_start = mid + 1;
        }
        if (back_start >= column)
            return false;

        int start = 0;
        int end = row - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target == matrix[back_start][mid]) 
                return true;
            else if (target > matrix[back_start][mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};
