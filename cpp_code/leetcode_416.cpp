class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return false;
        
        int sum = 0;
        for (auto num: nums) sum = sum + num;
        int target = sum / 2;
        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp;
        for (int i = 0; i <= len; i++) {
            vector<int> temp(target + 1, false);
            dp.push_back(temp);
        }

        // �������жϱ����ܲ���װ��(��������Ϊsum / 2 + 1)
        if (nums[0] <= target)
            dp[1][nums[0]] = true;

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= target; j++) {
                if (j > nums[i-1]) // ��װ || װ
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else if (j == nums[i-1])
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[len][target];
    }
};
