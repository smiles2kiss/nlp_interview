class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int mmax = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int width = j - i;
                int high = min(height[i], height[j]);
                mmax = max(mmax, width * high);
            }
        }
        return mmax;
    }
};
