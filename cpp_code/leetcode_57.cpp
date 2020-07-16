class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int n = intervals.size();
        if (newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        else if (newInterval[1] == intervals[0][0]) {
            intervals[0][0] = newInterval[0];
            return intervals;
        }
        if (newInterval[0] > intervals[n-1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        else if (newInterval[0] == intervals[n-1][1]) {
            intervals[n-1][1] = newInterval[1];
            return intervals;
        }

        int start = -1;
        int end = -1;
        if (newInterval[0] <= intervals[0][0]) {
            intervals[0][0] = newInterval[0];
            start = 0;
        } else {
            for (int i = 0; i < n; i++) {
                if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) {
                    start = i;
                    break;
                }
            }
            if (start == -1) {
                for (int i = 0; i < n - 1; i++) {
                    if (newInterval[0] > intervals[i][1] && newInterval[0] < intervals[i+1][0]) {
                        if (newInterval[1] >= intervals[i+1][0]) {
                            intervals[i+1][0] = newInterval[0];
                            start = i + 1;
                            break;
                        }
                    }
                }
            }
        }

        if (newInterval[1] >= intervals[n-1][1]) {
            intervals[n-1][1] = newInterval[1];
            end = n - 1;
        } else {
            for (int i = 0; i < n; i++) {
                if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                    end = i;
                    break;
                }
            }
            if (end == -1) {
                for (int i = 0; i < n-1; i++) {
                    if (newInterval[1] > intervals[i][1] && newInterval[1] < intervals[i+1][0]) {
                        if (newInterval[0] <= intervals[i][1]) {
                            intervals[i][1] = newInterval[1];
                            end = i;
                            break;
                        }
                    }
                }
            }
        }
        if (start == -1 && end == -1) {
            for (int i = 0; i < n - 1; i++) {
                if (newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i+1][0]) {
                    if (newInterval[1] > intervals[i][1] && newInterval[1] < intervals[i+1][0]) {
                        intervals.insert(intervals.begin() + i + 1, newInterval);
                        return intervals;
                    }
                }
            }
        }

        cout << start << endl;
        cout << end << endl;

        intervals[end][0] = intervals[start][0];
        vector<int> flag;
        for (int i = 0; i < n; i++) {
            if (i >= start && i < end)
                flag.push_back(0);
            else
                flag.push_back(1);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (flag[i] == 1)
                result.push_back(intervals[i]);
        }
        return result;
    }
};
