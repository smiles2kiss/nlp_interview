class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int curr_tank = 0;
        // 考虑一个基本思路，如果环路中的加油站总油量 大于 汽车环形一圈消耗的油量，则必定可以完成
        int start_position = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if (curr_tank < 0) {
                // 如果整个过程中能够到达，说明[0,..., i]的加油站油量太少，而[i+1, ..., n-1]油量较多
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
