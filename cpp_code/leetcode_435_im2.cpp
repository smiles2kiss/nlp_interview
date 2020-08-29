class Solution {
public:
    // �����Ǿ�̬����
    static bool cmp (vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len == 0) return 0;
        if (len == 1) return 0;

        // ����������㣬��С��������
        sort(intervals.begin(), intervals.end(), cmp);

        // �����С�������յ���
        int start = intervals[len - 1][0];
        int res = 0;

        for (int i = len - 2; i >= 0; i--) {
            if (intervals[i][1] > start) {
                res++;
            } else {
                start = intervals[i][0];
            }
        }
        return res;
    }
};
