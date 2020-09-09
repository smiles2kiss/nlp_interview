class Solution {
public:
    // row: ����
    // col: ����

    // ���ص����Ƿ񵽴�߽磬��Ǳ������еĵ���
    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size()) return;
        if (col < 0 || col >= grid[0].size()) return;

        // ��ǰλ���Ǻ�������Ѿ������ʹ���½��
        if (grid[row][col] != '1') return;

        // ��ǰλ����½�أ�������ǰλ��
        grid[row][col] = '2'; // ���Ϊ2��ʾ�Ѿ������ʹ�
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int len1 = grid.size();
        int len2 = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] == '1') {
                    // ��������껹δ����߽磬������1
                    res = res + 1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
