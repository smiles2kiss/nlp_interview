class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int len = arrays.size();
        int result = 0;
        int min_val = arrays[0][0];
        int max_val = arrays[0][arrays[0].size() - 1];
        for (int i = 1; i < len; i++) {
            int size = arrays[i].size();
            int temp1 = abs(arrays[i][size-1] - min_val);
            int temp2 = abs(arrays[i][0] - max_val);
            int temp = max(temp1, temp2);
            result = max(result, temp);
            min_val = min(arrays[i][0], min_val);
            max_val = max(arrays[i][size-1], max_val);
        }
        return result;
    }
};
