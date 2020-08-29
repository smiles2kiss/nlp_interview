class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        int row = matrix.size();  // �� 
        if (row == 0) return results;
        int column = matrix[0].size();  // �� 
        if (column == 0) return results;

        int start_i = 0;
        int start_j = 0;
        int max_i = row - 1;
        int max_j = column - 1;
        
        while (max_i - start_i >= 0 && max_j - start_j >= 0) {
            // �ȴ�ӡ��һ�� 
            for (int i = start_j; i <= max_j; i++) results.push_back(matrix[start_i][i]);
            // �ٴ�ӡ���ұ�һ��
            for (int i = start_i+1; i < max_i; i++) results.push_back(matrix[i][max_j]);
            // �ٴ�ӡ���±�һ��
            for (int i = max_j; i >= start_j; i--) {
                if (max_i > start_i) results.push_back(matrix[max_i][i]);
            } 
            // �ٴ�ӡ�����һ�� 
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
