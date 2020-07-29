class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // û������ʱ���ɲ��ü�
        if (points.size() == 0)
            return 0;

        // �ȶ����������ս����������򣬴�������һ�����
        sort(points.begin(), points.end(),
            [](const vector<int> &op1, const vector<int> &op2) {
                return op1[1] < op2[1];
            });
        
        int arrow = 1;
        int first_end = points[0][1];
        int start_x = points[0][1];
        int end_x = points[0][1];
        for (auto point: points) {
            start_x = point[0];
            end_x   = point[1];
            if (start_x > first_end) {
                arrow++;
                first_end = point[1];
            }
        }
        return arrow;
    }
};
