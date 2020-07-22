class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // �Ի���Ŀ�ʼʱ��������
        sort(intervals.begin(), intervals.end());
        // ������С��
        priority_queue<int, vector<int>, greater<int>> rooms;
        for (auto range: intervals) {
            int start = range[0];
            int end = range[1];
            if (rooms.empty()) {
                rooms.push(end);
                continue;
            } else if (rooms.top() <= start) { // �п��з���
                rooms.pop();             
                rooms.push(end);
            } else if (rooms.top() > start) { // û�п���ʱ��
                rooms.push(end);
            }
        }
        return rooms.size();
    }
};
