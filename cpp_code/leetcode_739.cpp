class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> ans(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int preIndex = stk.top();
                ans[preIndex] = i - preIndex;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
