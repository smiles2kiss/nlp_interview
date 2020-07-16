class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end());

        vector<int> flag;
        flag.push_back(1);

        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= intervals[i-1][1]) {
                intervals[i][0] = intervals[i-1][0];
                flag[i-1] = 0;
            }
            if (intervals[i][1] <= intervals[i-1][1]) {
                intervals[i][1] = intervals[i-1][1];
                flag[i-1] = 0;
            }
            flag.push_back(1);
        }
        vector<vector<int>> result;
        for (int i = 0; i < flag.size(); i++) {
            if (flag[i] == 1) {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
