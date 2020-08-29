class Solution {
public:
    // 必须是静态函数
    static bool cmp (vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        // 按照区间终点，从小到大排序
        sort(intervals.begin(), intervals.end(), cmp);

        // 获得最小的区间终点结点
        int end = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) { // 移除终点的区间
                res++;
            } else {
                end = intervals[i][1];
            }
        }
        return res;
    }
};
