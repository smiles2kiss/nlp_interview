class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int mn = INT_MIN;
        int ans = 0;
        for (auto num: preorder) {
            // 先找到最小值，之后满足所有的元素都比最小值大
            if (num < mn) return false;
            while (!s.empty() && num > s.top()) {
                mn = s.top(); s.pop();
            }
            s.push(num);
        }
        return true;
    }
};
