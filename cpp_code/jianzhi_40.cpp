class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //�������
        // priority_queue<int, vector<int>, greater<int>> q; // ��С��
        // �������
        // priority_queue<int, vector<int>, less<int>> q; // ����
        vector<int> result;
        if (k == 0) return result;

        priority_queue<int> q;
        for (auto num: arr) {
            if (q.size() == k) {
                if (num < q.top()) {
                    q.pop();
                    q.push(num);
                }
            } else {
                q.push(num);
            }
        }
        while (!q.empty()) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};
