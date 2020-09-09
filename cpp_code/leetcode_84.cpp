class Solution {
public:
    // 
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> left(n), right(n);

        // 单调最小栈
        // 枚举左侧小于其高度的柱子
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            } 
            left[i] = stk.empty() == true ? -1 : stk.top();
            stk.push(i);
        }

        // 枚举右侧小于其高度的柱子
        stk = stack<int>();
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() == true ? n : stk.top();
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
