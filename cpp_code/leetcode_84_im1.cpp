class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;    
        // 建立单调最小栈
        stack<pair<int,int>> q1, q2;
        unordered_map<int,int> hash_left;
        unordered_map<int,int> hash_right;    
        
        // 找到左边比当前高度小的最近的位置
        for (int i = 0; i < len; i++) {
            while (!q1.empty() && heights[i] <= q1.top().first) q1.pop();
            hash_left[i] = q1.empty() == true ? -1 : q1.top().second;
            q1.push(make_pair(heights[i], i));
        }

        // 找到右边比当前高度小的最近的位置
        for (int i = len - 1; i >= 0; i--) {
            while (!q2.empty() && heights[i] <= q2.top().first) q2.pop();
            hash_right[i] = q2.empty() == true ? len : q2.top().second;
            q2.push(make_pair(heights[i], i));
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            int size = heights[i] * (hash_right[i] - hash_left[i] - 1);
            res = max(res, size);
        }
        return res;
    }
};
