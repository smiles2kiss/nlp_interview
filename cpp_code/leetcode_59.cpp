class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> nums;
        for (int i = 1; i <= n * n; i++) nums.push_back(i);

        int start = 0, end = n - 1, count = 0;
        vector<vector<int>> results(n, vector<int>(n, 0));
        while (start < end) {
            // 打印第一行
            for (int j = start; j <= end; j++) {
                results[start][j] = nums[count];
                count = count + 1;
            }
            // 打印最后一列
            for (int i = start + 1; i < end; i++) {
                results[i][end] = nums[count];
                count = count + 1;
            }
            // 打印最后一行
            for (int j = end; j >= start; j--) {
                results[end][j] = nums[count];
                count = count + 1;
            }
            // 打印第一列
            for (int i = end - 1; i > start; i--) {
                results[i][start] = nums[count];
                count = count + 1;
            }
            start = start + 1;
            end = end - 1;
        }

        if (start == end) {
            results[start][start] = nums[count];
        }
        return results;
    }
};
