class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> data(len + 2, 1);
        for (int i = 1; i <= len; i++) 
            data[i] = nums[i-1];
        
        // 定义动态规划转移方程
        vector<vector<int>> dp;
        for (int i = 1; i <= len + 2; i++) {
            vector<int> temp(len + 2, 0);
            dp.push_back(temp);
        }

        for (int n = 3; n <= len + 2; n++) {
            // n 表示开区间的长度，范围为(3, len + 2)
            // 开区间的长度为3时，代表开区间中只有一个元素
            // 开区间的长度为len+2时，代表开区间中有len个元素
            for (int start = 0; start <= len + 2 - n; start++) {
                // 以n = 3为例，
                // 开区间的起点 start 的取值范围为(0, len - 1)
                // 开区间的终点位置可表示为start + n - 1
                // start = 0 时，代表
                //   开区间的起点在data数组的第0个位置，该位置的元素不包括在nums数组中，第一个位置为nums数组的第一个元素
                //   开区间的终点在data数组的第0 + n个位置           
                // start = len - 1时，代表
                //   开区间的起点在data数组的第len - 1个位置，第len个位置为nums数组的最后一个元素
                //   开区间的终点在data数组的第len + 1个位置，该位置的元素不包括在nums数组中
                for (int k = start + 1; k < start + n - 1; k++) {
                    // j 代表最后一个被戳破的元素位置
                    int end = start + n - 1;

                    int left = dp[start][k];
                    int right = dp[k][end];
                    int sum = left + data[start] * data[k] * data[end] + right;
                    dp[start][end] = max(dp[start][end], sum);
                }
            }
        }
        return dp[0][len + 1]; 
    }
};
