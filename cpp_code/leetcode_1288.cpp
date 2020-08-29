class Solution {
public:
    struct cmp_queue{
        bool operator() (const vector<int> &a, const vector<int> &b) {
            // if (a[0] < b[0]) return true;
            // if (a[0] == b[0] && a[1] < b[1]) return true;
            if (a[1] < b[1]) return true;
            return false;
        }
    };

    static bool cmp (const vector<int> &a, const vector<int> &b) {
        // if (a[0] < b[0]) return true;
        // if (a[0] == b[0] && a[1] < b[1]) return true;
        if (a[1] < b[1]) return true; // �����յ���������
        else if (a[1] == b[1] && a[0] > b[0]) return true; // ������㽵������
        else return false;
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len == 0) return len;
        if (len == 1) return len;
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < len; i++) {
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
        }
        
        // ȥ�������ǵ�����
        vector<bool> used(len, false);
        for (int i = len - 1; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (used[j]) continue;
                else {
                    if (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]) {
                        used[j] = true;
                        continue;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < len; i++) {
            if (!used[i]) count++;
        }
        return count;
    }
};
