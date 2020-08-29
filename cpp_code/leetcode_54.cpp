class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        int row = matrix.size();  // 行 
        if (row == 0) return results;
        int column = matrix[0].size();  // 列 
        if (column == 0) return results;

        int start_i = 0;
        int start_j = 0;
        int max_i = row - 1;
        int max_j = column - 1;
        
        while (max_i - start_i >= 0 && max_j - start_j >= 0) {
            // 先打印第一行 
            for (int i = start_j; i <= max_j; i++) results.push_back(matrix[start_i][i]);
            // 再打印最右边一列
            for (int i = start_i+1; i < max_i; i++) results.push_back(matrix[i][max_j]);
            // 再打印最下边一行
            for (int i = max_j; i >= start_j; i--) {
                if (max_i > start_i) results.push_back(matrix[max_i][i]);
            } 
            // 再打印最左边一列 
            for (int i = max_i - 1; i > start_i; i--) {
                if (max_j > start_j) results.push_back(matrix[i][start_j]);
            }
            
            start_i = start_i + 1;
            start_j = start_j + 1;
            max_i = max_i - 1;
            max_j = max_j - 1; 
        }
        return results;
    }
};
