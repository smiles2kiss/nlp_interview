class Solution {
public:
    // �����Ǿ�̬����
    static bool cmp (vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        // ���������յ㣬��С��������
        sort(intervals.begin(), intervals.end(), cmp);

        // �����С�������յ���
        int end = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) { // �Ƴ��յ������
                res++;
            } else {
                end = intervals[i][1];
            }
        }
        return res;
    }
};
