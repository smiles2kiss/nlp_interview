class Solution {
public:
    // row: ����
    // col: ����

    // ���ص�������
    int index = 2;
    unordered_map<int, int> hash_table;
    int dfs(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size()) return 0;
        if (col < 0 || col >= grid[0].size()) return 0;

        // ��ǰλ���Ǻ�������Ѿ������ʹ���½��
        if (grid[row][col] != 1) return 0;

        // ��ǰλ����½�أ�������ǰλ��
        grid[row][col] = index; // ���Ϊindex��ʾ�Ѿ������ʹ�
        int res1 = dfs(grid, row + 1, col);
        int res2 = dfs(grid, row - 1, col);
        int res3 = dfs(grid, row, col + 1);
        int res4 = dfs(grid, row, col - 1);
        return res1 + res2 + res3 + res4 + 1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int len1 = grid.size();
        int len2 = grid[0].size();

        int res = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j);
                    res = max(res, size);
                    hash_table[index] = size;
                    index = index + 1;
                }
            }
        }
        
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                // �����ҪȾɫ���ж���Χ�����Ĺ��ж���½�����
                if (grid[i][j] == 0) {
                    int sum = 0;
                    unordered_set<int> indexs;
                    if (i - 1 >= 0 && i - 1 < len1) {
                        int color = grid[i-1][j];
                        if (color >= 2) indexs.insert(color);
                    }
                    if (i + 1 >= 0 && i + 1 < len1) {
                        int color = grid[i+1][j];
                        if (color >= 2) indexs.insert(color);
                    }
                    if (j - 1 >= 0 && j - 1 < len2) {
                        int color = grid[i][j-1];
                        if (color >= 2) indexs.insert(color);
                    }
                    if (j + 1 >= 0 && j + 1 < len2) {
                        int color = grid[i][j+1];
                        if (color >= 2) indexs.insert(color);
                    }
                    for (auto idx:indexs) sum += hash_table[idx];
                    res = max(res, sum + 1);
                }
            }
        }
        return res;
    }
};
