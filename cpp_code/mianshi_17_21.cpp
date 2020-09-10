class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left_max(len, -1);
        vector<int> right_max(len, -1);
        vector<int> q1; // 大根堆
        vector<int> q2; // 大根堆
        q1.push_back(0);
        q2.push_back(0);
        for (int i = 0; i < len; i++) {
            if (i == 0) left_max[i] = -1;
            else {
                if (height[i] <= q1.back()) left_max[i] = q1.back();
                else left_max[i] = -1;
            }
            if (height[i] > q1.back()) q1.push_back(height[i]);
        }
        for (int i = len-1; i >= 0; i--) {
            if (i == len - 1) right_max[i] == -1;
            else {
                if (height[i] <= q2.back()) right_max[i] = q2.back();
                else right_max[i] = -1;
            }
            if (height[i] > q2.back()) q2.push_back(height[i]);
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (left_max[i] >= height[i] && right_max[i] >= height[i])
                res += min(left_max[i], right_max[i]) - height[i]; 
        }
        return res;
    }
};
