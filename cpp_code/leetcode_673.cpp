class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        // 动态规划找到递增子序列的最大长度
        int len = nums.size();
        if (len == 1) return len;
        vector<int> length(len, 1);  // 最长递增子序列的最大长度
        vector<int> count(len, 1);   // 最长递增子序列的最大值
        
        // 以i为起点，j为终点的最大递增子序列的长度
        int max_len = 1;
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[j] > nums[i]) {
                    if (length[j] < length[i] + 1) {
                        length[j] = length[i] + 1;
                        count[j] = count[i];
                    } else if (length[j] == length[i] + 1) {
                        count[j] = count[j] + count[i];
                    }
                }
                if (length[j] > max_len)
                    max_len = length[j];
            }
        }

        int max_num = 0;
        for (int i = 0; i < len; i++) {
            if (length[i] == max_len) {
                max_num = max_num + count[i];
            }
        }
        return max_num;
    }
};
