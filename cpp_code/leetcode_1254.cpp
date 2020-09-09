class Solution {
public:
    // ��յ����������������Χȫ��ˮ��
    bool dfs(vector<vector<int>> &grid, int row, int col) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        // �����Ƿ񵽴�߽�
        if (row < 0 || row >= len1) return true; 
        if (col < 0 || col >= len2) return true;

        // ��ʱδ�Ӵ����߽�
        if (grid[row][col] != 0) return false;

        // ��Ƿ��ʹ��ĵ���
        grid[row][col] = 2;
        bool res1 = dfs(grid, row + 1, col);
        bool res2 = dfs(grid, row - 1, col);
        bool res3 = dfs(grid, row, col + 1);
        bool res4 = dfs(grid, row, col - 1);
        return res1 || res2 || res3 || res4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int res = 0;
        int len1 = grid.size();
        int len2 = grid[0].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] == 0) {
                    bool flag = dfs(grid, i, j);
                    // ��������ֲ�û�нӴ����߽�
                    if (!flag) res = res + 1;
                }
            }
        }

        return res;
    }
};
