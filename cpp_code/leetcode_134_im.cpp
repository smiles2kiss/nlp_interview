class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int curr_tank = 0;
        // ����һ������˼·�������·�еļ���վ������ ���� ��������һȦ���ĵ���������ض��������
        int start_position = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if (curr_tank < 0) {
                // ��������������ܹ����˵��[0,..., i]�ļ���վ����̫�٣���[i+1, ..., n-1]�����϶�
                start_position = i + 1;
                curr_tank = 0;
            }
        }
        if (total_tank >= 0)
            return start_position;
        else 
            return -1;
    }
};
