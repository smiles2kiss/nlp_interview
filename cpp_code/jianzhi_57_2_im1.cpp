class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1; // ��߽�
        int j = 1; // �ұ߽�
        int sum = 0; // �����е�Ԫ�غ�

        vector<vector<int>> results;
        while (i <= target / 2) {
            if (sum < target) {
                sum += j; // �ұ߽������ƶ�
                j++;
            } else if (sum > target) {
                sum -= i; // ��߽������ƶ�
                i++;
            } else {
                // ��¼���
                vector<int> result;
                for (int k = i; k < j; k++) result.push_back(k);
                results.push_back(result);
                // ��߽������ƶ�
                sum -= i;
                i++;
            }
        }
        return results;
    }
};
