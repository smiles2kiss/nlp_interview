class Solution {
public:
    // 必须是静态函数
    static bool cmp (vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len == 0) return 0;
        if (len == 1) return 0;

        // 按照区间起点，从小到大排序
        sort(intervals.begin(), intervals.end(), cmp);

        // 获得最小的区间终点结点
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
