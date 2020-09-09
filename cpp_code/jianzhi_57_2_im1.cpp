class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1; // 左边界
        int j = 1; // 右边界
        int sum = 0; // 数组中的元素和

        vector<vector<int>> results;
        while (i <= target / 2) {
            if (sum < target) {
                sum += j; // 右边界向右移动
                j++;
            } else if (sum > target) {
                sum -= i; // 左边界向右移动
                i++;
            } else {
                // 记录结果
                vector<int> result;
                for (int k = i; k < j; k++) result.push_back(k);
                results.push_back(result);
                // 左边界向右移动
                sum -= i;
                i++;
            }
        }
        return results;
    }
};
