class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int mn = INT_MIN;
        int ans = 0;
        for (auto num: preorder) {
            // ���ҵ���Сֵ��֮���������е�Ԫ�ض�����Сֵ��
            if (num < mn) return false;
            while (!s.empty() && num > s.top()) {
                mn = s.top(); s.pop();
            }
            s.push(num);
        }
        return true;
    }
};
