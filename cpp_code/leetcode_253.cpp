class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 以会议的开始时间来排序
        sort(intervals.begin(), intervals.end());
        // 建立最小堆
        priority_queue<int, vector<int>, greater<int>> rooms;
        for (auto range: intervals) {
            int start = range[0];
            int end = range[1];
            if (rooms.empty()) {
                rooms.push(end);
                continue;
            } else if (rooms.top() <= start) { // 有空闲房间
                rooms.pop();             
                rooms.push(end);
            } else if (rooms.top() > start) { // 没有空闲时间
                rooms.push(end);
            }
        }
        return rooms.size();
    }
};
