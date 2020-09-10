class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') { 
                    if (i > 0 && matrix[i-1][j] == '1') heights[j] = heights[j] + 1;
                    else heights[j] = 1;
                } else {
                    heights[j] = 0;
                }
            }

            unordered_map<int,int> hash_left;
            unordered_map<int,int> hash_right;
            // 单调最小栈
            stack<pair<int,int>> q1, q2;
            for (int j = 0; j < col; j++) {
                while (!q1.empty() && heights[j] <= q1.top().first) q1.pop();
                hash_left[j] = q1.empty() == true ? -1 : q1.top().second;
                q1.push(make_pair(heights[j], j));
            }
            for (int j = col-1; j >= 0; j--) {
                while (!q2.empty() && heights[j] <= q2.top().first) q2.pop();
                hash_right[j] = q2.empty() == true ? col : q2.top().second;
                q2.push(make_pair(heights[j], j));
            }

            for (int j = 0; j < col; j++) {
                int size = heights[j] * (hash_right[j] - hash_left[j] - 1);
                res = max(res, size);
            }
        }
        return res;
    }
};
