class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        vector<vector<int>> dist(len1, vector<int>(len2, 0));
        vector<vector<int>> seen(len1, vector<int>(len2, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                    seen[i][j] = 1;
                }
            }
        }

        int dirs[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        // 广度优先搜索
        while (!q.empty()) {
            pair<int, int> item = q.front(); q.pop();
            int i = item.first;
            int j = item.second;
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];

                if (ni >= 0 && ni < len1 && nj >= 0 && nj < len2 && seen[ni][nj] == 0) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push(make_pair(ni, nj));
                    seen[ni][nj] = 1;
                }
            }
        }
        return dist;
    }
};
